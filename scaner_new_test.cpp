

//-------------------------------------------------------------------------------------------
//Тестирование работы USB для сканера Гослото
//-------------------------------------------------------------------------------------------
#pragma once
#pragma comment(lib,"Setupapi.lib")

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#define _CRT_SECURE_NO_DEPRECATE
#undef UNICODE
//-------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <initguid.h>
#include <setupapi.h>

//90873fdf-61a8-11d1-fa5e-00c04fb3728b
DEFINE_GUID(GUID_CLASS_SCANNER_GOSLOTO,
0x90873fdf, 0x61a8, 0x11d1, 0xfa, 0x5e, 0, 0xc0, 0x4f, 0xb3, 0x72, 0x8b);

#define CIS_CHIP_NUM (7)//количество чипов CIS-a
#define CIS_CHIP_SIZE (144)//количество точек в чипе CIS-a
#define CIS_POINTS (CIS_CHIP_NUM*CIS_CHIP_SIZE)//общее количество точек CIS-а
#define CIS_STR_DATA_LEN (1024)//длина данных строки CIS-a
#define MAX_STR_NUM (8*1024)//максимальное количество строк
#define SIZE_BUF_IMAGE (MAX_STR_NUM*1024+2048)//размер буфера образа

#pragma pack(1)
//Структура строки основного образа
typedef struct {
    WORD code;//код 0x5555
    BYTE st1,st2;
    BYTE data[CIS_POINTS];//данные CIS-a
    float tacho;//значение тахометра
    WORD left,right;//левая и правая границы, 0xFFFF если билета нет
    BYTE w_ir;//подсветка CIS: 0 - W, not 0 - IR
    BYTE uv,mid,end;//sensors
} main_image_CIS;
//Структура строки тестового образа
typedef struct {
    WORD code;//код 0xAAAA - W, 0xBBBB - IR
    BYTE black[14];//уровень черного
    BYTE data[CIS_POINTS];//данные CIS-a
} test_image_CIS;
//Обединение для строки образа
typedef union {
    main_image_CIS mi;
    test_image_CIS ti;
} image_CIS;
#pragma pack()

HANDLE husb=INVALID_HANDLE_VALUE;
HANDLE hin=INVALID_HANDLE_VALUE;
INPUT_RECORD irec[1024];
BYTE buf_image[SIZE_BUF_IMAGE+128*1024];//буфер образа CIS-a
int adr_buf_image;	//адрес в буфере образа CIS-a
DWORD image_hnum;		//количество точек по вертикали
DWORD flag_test;		//1 - тестовый режим, 0 - нормальный
int ADC_down,ADC_up;	//значения порогов АЦП
int PWM_motor,CIS_level;//значение PWM двигателя, порог CIS-a
int num_out_file;

#include <QtCore>
#include "emitterclass.h"
EmitterClass image_simple;
EmitterClass image_sensors;
QByteArray image_buffer_simple; //буфер со сканом купюры
QByteArray image_buffer_sensors; //буфер со сканом купюры sensors
//----------------------------------------------------------------------------------------------------
#pragma pack(1)
struct bmpHeader_new {
    WORD	type;		// = 0x4D42
    DWORD	file_size;	//размер файла
    DWORD	reserve;	// = 0
    DWORD	offset;		// = 0x36 + 1024 - смещение данных
    DWORD	size2;		// = 0x28 - размер 2-й структуры
    LONG	w;		//ширина
    LONG	h;		//высота
    WORD	planes;		// = 1, количество цветовых плоскостей
    WORD	bits;		// = 8, количество битов в пикселе
    DWORD	compres;	// = 0, тип сжатия
    DWORD	image_size;	//размер изображения в байтах
    LONG	p1, p2;		//доп. параметры = 0
    DWORD	p3, p4;		//доп. параметры = 0
};
#pragma pack()
bmpHeader_new header1 = {0x4D42, 0, 0, 0x36+1024, 0x28, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0};
BYTE bmp_palitra_new[1024];
//-------------------------------------------------------------------------------------------
//void printMes(void)
//{
//    LPVOID lpMsgBuf; char buf_OEM[512];
//    DWORD dw = GetLastError();
//    FormatMessage(
//        FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,NULL,dw,
//        MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),(LPTSTR)&lpMsgBuf,0,NULL
//    );
//    CharToOem((LPCSTR)lpMsgBuf,buf_OEM);
//    printf("ERROR code = %d | %s",dw,buf_OEM);
//    LocalFree(lpMsgBuf);
//}
//-------------------------------------------------------------------------------------------
int openHandle(void)
{
    char buf_name[512];
    ULONG predictedLength = 0;
    ULONG requiredLength = 0;
    PSP_DEVICE_INTERFACE_DETAIL_DATA functionClassDeviceData = NULL;
    HDEVINFO hardwareDeviceInfo;
    SP_DEVICE_INTERFACE_DATA deviceInfoData;
//	SP_DEVINFO_DATA devinfo;
    BOOL res;

    hardwareDeviceInfo = SetupDiGetClassDevs((LPGUID)&GUID_CLASS_SCANNER_GOSLOTO,//&GUID_CLASS_PRINTER,
                        NULL,NULL,(DIGCF_PRESENT|DIGCF_DEVICEINTERFACE));

//	devinfo.cbSize = sizeof(SP_DEVINFO_DATA);
//	res = SetupDiEnumDeviceInfo(hardwareDeviceInfo,0,&devinfo);
//	res = SetupDiRemoveDevice(hardwareDeviceInfo,&devinfo);
//	res = SetupDiRestartDevices(hardwareDeviceInfo,&devinfo);

    deviceInfoData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
    res = SetupDiEnumDeviceInterfaces(hardwareDeviceInfo,NULL,
                (LPGUID)&GUID_CLASS_SCANNER_GOSLOTO,//&GUID_CLASS_PRINTER,
                0,&deviceInfoData);
    SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo,&deviceInfoData,NULL,0,&requiredLength,NULL);
    predictedLength = requiredLength;
    functionClassDeviceData = (PSP_DEVICE_INTERFACE_DETAIL_DATA)malloc(predictedLength+16);
    functionClassDeviceData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
    SetupDiGetDeviceInterfaceDetail(hardwareDeviceInfo,&deviceInfoData,functionClassDeviceData,
                                    predictedLength,&requiredLength,NULL);
    strncpy(buf_name,functionClassDeviceData->DevicePath,508); buf_name[508] = 0;
    free(functionClassDeviceData);
    SetupDiDestroyDeviceInfoList(hardwareDeviceInfo);
    husb = CreateFile(buf_name,GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
    if (husb == INVALID_HANDLE_VALUE) return -1;
    return 0;
}
//-------------------------------------------------------------------------------------------
//Чтение информации со сканера
int scaner_read(void)
{
    DWORD b=0;
    BYTE buf[2*1024];

//	return 0;

    BOOL res = ReadFile(husb,buf,1024,&b,NULL);
    if (res == 0) {
        return -10;
    }
    if (b==0) return 0;
    if (adr_buf_image < sizeof(buf_image)) {
        memcpy(&buf_image[adr_buf_image],buf,b);
        adr_buf_image += b;
    }
    return b;
}
//------------------------------------------------------------------------------------
//Вывод команды с кодом c
int command(int c)
{
    DWORD b=0;
    BYTE buf[8]={0,0,0,0,0,0,0,0};
    buf[0] = (BYTE)c; buf[1] = (BYTE)c;
    WriteFile(husb,buf,2,&b,NULL);
    if (b!=2) {
        printf("ERROR output, b = %d\n",b);
        return 1;
    }
    switch (c) {
        case 1:
            printf("Command scan main ...\n");
            break;
        case 2:
            printf("Command STOP ALL ...\n");
            break;
        case 3:
            printf("Command scan test ...\n");
            break;
        case 8:
            printf("Command scan sensor ...\n");
            break;
        case 4:
            printf("Command test ...\n");
            break;
        case 13:
            printf("Command roll for ...\n");
            break;
        case 14:
            printf("Command roll rev ...\n");
            break;
        default :
            printf("ERROR command code = %d\n",c);
            break;
    }
    return 0;
}//------------------------------------------------------------------------------------
//Вывод команды с кодом c и байтом b1
int command(int c,int b1)
{
    if ((c != 3)&&(c != 13)) {
        printf("ERROR command, code = %d %d\n",c,b1);
        return 2;
    }
    DWORD b=0;
    BYTE buf[8]={0,0,0,0,0,0,0,0};
    buf[0] = (BYTE)c; buf[1] = (BYTE)c; buf[2] = (BYTE)b1;
    WriteFile(husb,buf,3,&b,NULL);
    if (b!=3) {
        printf("ERROR output, b = %d\n",b);
        return 1;
    }
    printf("Command scan test ...\n");
    return 0;
}
//------------------------------------------------------------------------------------
//Вывод команды с кодом c и байтами b1,b2,b3,b4
int command(int c,int b1,int b2,int b3,int b4)
{
    if (c != 7) {
        printf("ERROR command, code = %d %d %d %d %d\n",c,b1,b2,b3,b4);
        return 2;
    }
    DWORD b=0;
    BYTE buf[8]={0,0,0,0,0,0,0,0};
    buf[0] = (BYTE)c; buf[1] = (BYTE)c;
    buf[2] = (BYTE)b1; buf[3] = (BYTE)b2;
    buf[4] = (BYTE)b3; buf[5] = (BYTE)b4;
    WriteFile(husb,buf,6,&b,NULL);
    if (b!=6) {
        printf("ERROR output, b = %d\n",b);
        return 1;
    }
    printf("Command ADC level ...\n");
    return 0;
}
//-------------------------------------------------------------------------------------------
//Проверка состояния
int read_state(void)
{
    DWORD b=0,i;
    BYTE buf[64];
    int state;
    BOOL res = ReadFile(husb,buf,16,&b,NULL);
//	res = ReadFile(husb,buf,6,&b,NULL);
    if (b >= 2) {
        state = buf[0] + ((WORD)buf[1] << 8);
        printf("STATE = %04X",state);
        for (i=2;i<b;i++) printf(" %02X ",buf[i]);
        printf("\n");
    }
    else {
        printf("ERROR read state, b = %d\n",b);
        state = -1;
    }
    return state;
}
int read_state0(void)
{
    DWORD b=0;
    BYTE buf[64];
    int state;
    BOOL res = ReadFile(husb,buf,16,&b,NULL);
    if (b >= 2) {
        state = buf[0] + ((WORD)buf[1] << 8);
    }
    else {
        state = -1;
    }
    return state;
}
//-------------------------------------------------------------------------------------------
void save_param(FILE *bmp,int val)
{
    int i;
    fputc(128, bmp); fputc(128, bmp); fputc(128, bmp); fputc(128, bmp);
    for (i=0;i<256;i++) {
        if (i == val) fputc(255, bmp);
        else fputc(0, bmp);
    }
}




//Запись буфера образа
void save_image(void)
{
//-----------------------------------------------------------
    QBuffer buffer(&image_buffer_simple);
    buffer.open(QIODevice::WriteOnly);
//-----------------------------------------------------------

    FILE *bin,*bmp;
    DWORD CIS_len,i;
    int adr_max,flag_regim;
    image_CIS *buf_image_CIS;
    BYTE *buf,c;
    char nbin[64],nbmp[64];

    sprintf(nbin,"image%05d.bin",num_out_file);
    sprintf(nbmp,"image%05d.bmp",num_out_file);
    num_out_file++;

    adr_max = adr_buf_image;
    printf("Save image ...\n");
    bin = fopen(nbin,"wb");
    fwrite(buf_image,adr_buf_image,1,bin);
    fclose(bin);
    printf("Save '%s' - O'k\n",nbin);
    CIS_len = CIS_STR_DATA_LEN;
    for (i=0;i<255;i++) {
        buf = &bmp_palitra_new[i*4];
        buf[0] = buf[1] = buf[2] = (BYTE)i;
        buf[3] = 0;
    }
    buf = &bmp_palitra_new[255*4];
    buf[2] = 255;
    buf[1] = buf[0] = buf[3] = 0;

//	th = fopen("tacho.txt","wt");

    buf_image_CIS = (image_CIS*)buf_image;
    image_hnum = adr_max/CIS_len;
    if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
        header1.w = CIS_POINTS;
        header1.h = image_hnum+1;
        flag_regim = 1;
    }
    else {
        header1.w = CIS_len;
        header1.h = image_hnum+1;
        flag_regim = 0;
    }
    header1.image_size = header1.h*header1.w;
    header1.file_size = header1.image_size + 0x36 + 1024;
    bmp = fopen(nbmp,"wb");
    if (bmp == NULL) return;
    buffer.write((char*)&header1,sizeof(header1)); //пишем в буфер для основной проги
    buffer.write((char*)bmp_palitra_new,1024); //пишем в буфер для основной проги
    fwrite(&header1,sizeof(header1),1,bmp);
    fwrite(bmp_palitra_new,1024,1,bmp);
    DWORD adr_work,s;
    adr_work = 0;
    if (flag_regim) {//рабочий режим
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            adr_work += CIS_len;
            if (buf_image_CIS->mi.w_ir == 0) continue;//пропуск белого
            for (i=0;i<CIS_POINTS;i++) {
                c = buf_image_CIS->mi.data[i];
                if (c == 255) c = 254;
                if (i == buf_image_CIS->mi.left) c = 255;
                if (i == buf_image_CIS->mi.right) c = 255;
                fputc(c, bmp);
                buffer.putChar(c);//пишем в буфер для основной проги
            }
        }
        for (i=0;i<CIS_POINTS;i++) {
            fputc(255, bmp);
            buffer.putChar(255);//пишем в буфер для основной проги
        }
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            adr_work += CIS_len;
            if (buf_image_CIS->mi.w_ir) continue;//пропуск IR
            for (i=0;i<CIS_POINTS;i++) {
                c = buf_image_CIS->mi.data[i];
                if (c == 255) c = 254;
                if (i == buf_image_CIS->mi.left) c = 255;
                if (i == buf_image_CIS->mi.right) c = 255;
                fputc(c, bmp);
                buffer.putChar(c);//пишем в буфер для основной проги
            }
        }
    }
    else {//тестовый режим
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            if (buf_image_CIS->ti.code == 0xBBBB) {//IR
                for (i=0;i<CIS_len;i++) {
                    c = buf_image[adr_work+i];
                    if (c == 255) c = 254;
                    fputc(c, bmp);
                    buffer.putChar(c);//пишем в буфер для основной проги
                }
            }
            adr_work += CIS_len;
        }
        for (i=0;i<CIS_len;i++) {
            fputc(255, bmp);
            buffer.putChar(255);//пишем в буфер для основной проги
        }
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            if (buf_image_CIS->ti.code == 0xAAAA) {//W
                for (i=0;i<CIS_len;i++) {
                    c = buf_image[adr_work+i];
                    if (c == 255) c = 254;
                    fputc(c, bmp);
                    buffer.putChar(c);//пишем в буфер для основной проги
                }
            }
            adr_work += CIS_len;
        }
    }
    buffer.close();//stas
    image_simple.ImageChangeFunction();
    fclose(bmp);
//	fclose(th);
    printf("Save '%s' - O'k\n",nbmp);
    return;
}



void save_image_sensors(void)
{
    //-----------------------------------------------------------
    QBuffer buffer(&image_buffer_simple);
    buffer.open(QIODevice::WriteOnly);
    //-----------------------------------------------------------

    FILE *bin,*bmp;
    DWORD CIS_len,i;
    int adr_max,flag_regim;
    image_CIS *buf_image_CIS;
    BYTE *buf,c;

    adr_max = adr_buf_image;
    printf("Save image ...\n");
    bin = fopen("image.bin","wb");
    fwrite(buf_image,adr_buf_image,1,bin);
    fclose(bin);
    printf("Save image.bin - O'k\n");
    CIS_len = CIS_STR_DATA_LEN;
    for (i=0;i<255;i++) {
        buf = &bmp_palitra_new[i*4];
        buf[0] = buf[1] = buf[2] = (BYTE)i;
        buf[3] = 0;
    }
    buf = &bmp_palitra_new[255*4];
    buf[2] = 255;
    buf[1] = buf[0] = buf[3] = 0;

//	th = fopen("tacho.txt","wt");

    buf_image_CIS = (image_CIS*)buf_image;
    image_hnum = adr_max/CIS_len;
    if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
        header1.w = CIS_POINTS + (4 + 256)*6;
        header1.h = image_hnum+1;
        flag_regim = 1;
    }
    else {
        header1.w = CIS_len;
        header1.h = image_hnum+1;
        flag_regim = 0;
    }
    header1.image_size = header1.h*header1.w;
    header1.file_size = header1.image_size + 0x36 + 1024;
    bmp = fopen("image.bmp","wb");
    if (bmp == NULL) return;
    buffer.write((char*)&header1,sizeof(header1)); //пишем в буфер для основной проги
    buffer.write((char*)bmp_palitra_new,1024); //пишем в буфер для основной проги
    fwrite(&header1,sizeof(header1),1,bmp);
    fwrite(bmp_palitra_new,1024,1,bmp);
    DWORD adr_work,s;
    adr_work = 0;
    if (flag_regim) {//рабочий режим
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            adr_work += CIS_len;
            if (buf_image_CIS->mi.w_ir == 0) continue;//пропуск белого
            int tach;
            for (i=0;i<CIS_POINTS;i++) {
                c = buf_image_CIS->mi.data[i];
                if (c == 255) c = 254;
                if (i == buf_image_CIS->mi.left) c = 255;
                if (i == buf_image_CIS->mi.right) c = 255;
                fputc(c, bmp);
            }
            tach = (int)(128.0f * buf_image_CIS->mi.tacho);
            save_param(bmp,tach);
            save_param(bmp,buf_image_CIS->mi.uv);
            save_param(bmp,buf_image_CIS->mi.st1);
            save_param(bmp,buf_image_CIS->mi.st2);
            save_param(bmp,buf_image_CIS->mi.mid);
            save_param(bmp,buf_image_CIS->mi.end);
        }
        for (i=0;i<CIS_POINTS + (4 + 256)*6;i++) {
            fputc(255, bmp);
        }
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            adr_work += CIS_len;
            if (buf_image_CIS->mi.w_ir) continue;//пропуск IR
            int tach;
            for (i=0;i<CIS_POINTS;i++) {
                c = buf_image_CIS->mi.data[i];
                if (c == 255) c = 254;
                if (i == buf_image_CIS->mi.left) c = 255;
                if (i == buf_image_CIS->mi.right) c = 255;
                fputc(c, bmp);
                buffer.putChar(c);//пишем в буфер для основной проги
            }
            tach = (int)(128.0f * buf_image_CIS->mi.tacho);
            save_param(bmp,tach);
            save_param(bmp,buf_image_CIS->mi.uv);
            save_param(bmp,buf_image_CIS->mi.st1);
            save_param(bmp,buf_image_CIS->mi.st2);
            save_param(bmp,buf_image_CIS->mi.mid);
            save_param(bmp,buf_image_CIS->mi.end);
        }
    }
    else {//тестовый режим
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            if (buf_image_CIS->ti.code == 0xBBBB) {//IR
                for (i=0;i<CIS_len;i++) {
                    c = buf_image[adr_work+i];
                    if (c == 255) c = 254;
                    fputc(c, bmp);
                    buffer.putChar(c);//пишем в буфер для основной проги
                }
            }
            adr_work += CIS_len;
        }
        for (i=0;i<CIS_len;i++) {
            fputc(255, bmp);
            buffer.putChar(255);//пишем в буфер для основной проги
        }
        adr_work = 0;
        for (s=0;s<image_hnum;s++) {
            buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
            if (buf_image_CIS->ti.code == 0xAAAA) {//W
                for (i=0;i<CIS_len;i++) {
                    c = buf_image[adr_work+i];
                    if (c == 255) c = 254;
                    fputc(c, bmp);
                    buffer.putChar(c);//пишем в буфер для основной проги
                }
            }
            adr_work += CIS_len;
        }
    }
    image_sensors.ImageChangeFunction();
    buffer.close();
    fclose(bmp);
//	fclose(th);
    printf("Save image.bmp - O'k\n");
    return;
}
//------------------------------------------------------------------------------------
int read_image(int str_num)
{
    int res,adr_end,flag_stop;
    if (str_num <= 0) str_num = MAX_STR_NUM;
    adr_end = str_num*1024;
    adr_buf_image = flag_stop = 0;
    while (1) {
        res = scaner_read();
        if (res == -10) {
            command(2);
            printf("ERROR read image, input %d bytes\n",adr_buf_image);
            if (adr_buf_image > 0) save_image();
            break;
        }
        else if ((res == 0)&&(flag_stop == 1)) {
            printf("Input %d bytes\n",adr_buf_image);
            save_image();
            break;
        }
        if (adr_buf_image >= adr_end) {
            if (flag_stop == 0) {command(2); flag_stop = 1;}
        }
    }
    return adr_buf_image;
}
//------------------------------------------------------------------------------------
int read_image_main(void)
{
    int adr_end,flag_stop,flag_begin,snum,res,num_str;
    main_image_CIS buf;
    DWORD b;

    adr_end = MAX_STR_NUM * 1024;
    adr_buf_image = flag_stop = flag_begin = snum = num_str = 0;

    res = command(8);
    if (res) goto end_error_not_connect;
    res = read_state0();
    if (res < 0) goto end_error_not_connect;
    int np;
    np = 0;
    while (1) {
        Sleep(10);
        res = read_state0();
        if (res < 0) goto end_error_not_connect;
        if ((res & 0x0C00) == 0x0C00) {
            if (++np > 5) break;
        }
        else np = 0;
    }
    Sleep(10);
    res = command(2);
    if (res) goto end_error_not_connect;
    Sleep(10);

    command(1);
    while (1) {
        BOOL res1 = ReadFile(husb,&buf,1024,&b,NULL);
        if (res1 == 0) {
            command(2);
            printf("ERROR read image, input %d bytes\n",adr_buf_image);
            if (adr_buf_image > 0) save_image();
            break;
        }
        else if (b == 1024) {
            if (++num_str < 12) continue;
            if (flag_begin) {
                if ((buf.left == 0xFFFF)||(buf.right == 0xFFFF)) {
                    if (++snum > 48) {
                        if (flag_stop == 0) {command(2); flag_stop = 1;}
                    }
                }
                else snum = 0;
                memcpy(&buf_image[adr_buf_image],&buf,b);
                adr_buf_image += b;
            }
            else {
                if ((buf.left != 0xFFFF)&&(buf.right != 0xFFFF)) {
                    flag_begin = 1;
                    memcpy(&buf_image[adr_buf_image],&buf,b);
                    adr_buf_image += b;
                }
            }
        }
        else if ((b == 0)&&(flag_stop == 1)) {
            printf("Input %d bytes\n",adr_buf_image);
            save_image();
            break;
        }
        if (adr_buf_image >= adr_end) {
            if (flag_stop == 0) {command(2); flag_stop = 1;}
        }
    }
    return adr_buf_image;
end_error_not_connect:
    printf("ERROR scanner connect\n");
    return 0;
}

#include <QDebug>

//------------------------------------------------------------------------------------------

int scaner_init(void)
{
    int res;
    DWORD i,irn=0;
    qDebug() << "Input begin file num: 1";
    //printf("Input begin file num:");
    //scanf("\n%d",&num_out_file);
    num_out_file=1;
    //printf("Begin file num = %d\n",num_out_file);
    qDebug() << "Begin file num = 1";
    for (i=0;i<10;i++) {
        res = openHandle();
        if (res == 0) break;
        qDebug() << "Wait open USB device...\n";
        //printf("Wait open USB device...\n");
        Sleep(1000);
    }
    if (res)
    {
        //printf("ERROR open device res = %d\n",res);
        qDebug() << "ERROR open device res = "<< res;
        getchar();
    }
    else
    {
        //printf("Open USB device - O'k\n");
        qDebug() << "Open USB device - O'k";
    }
    adr_buf_image = 0;
    hin = GetStdHandle(STD_INPUT_HANDLE);
    irn=0;
    return res;
}





void main_test_test(void)
{
    int res;
    DWORD i,irn=0;
    qDebug()<<"Input begin file num:";
    printf("Input begin file num:");
    //scanf("\n%d",&num_out_file);
    num_out_file=1;
    qDebug()<<"Begin file num ="<<num_out_file;
    printf("Begin file num = %d\n",num_out_file);
    for (i=0;i<10;i++) {
        res = openHandle();
        if (res == 0) break;
        qDebug()<<"Wait open USB device...";
        printf("Wait open USB device...\n");
        Sleep(1000);
    }
    if (res) {
        qDebug()<<"ERROR open device res ="<<res;
        printf(
        "ERROR open device res = %d\n",res);
        getchar();
    }
    else
    {
        qDebug()<<"Open USB device - O'k";
        printf("Open USB device - O'k\n");
    }

    adr_buf_image = 0;
    hin = GetStdHandle(STD_INPUT_HANDLE);
    irn=0;

    read_image_main();

}
//------------------------------------------------------------------------------------------

