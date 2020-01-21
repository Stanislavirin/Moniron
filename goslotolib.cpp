//--------------------------------------------------------------------------------------------
//Файл тестирования dll
//--------------------------------------------------------------------------------------------
#pragma once
#pragma comment(lib,"libgosloto_new.lib")

#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE
#undef UNICODE
//--------------------------------------------------------------------------------------------
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include "goslotolib.h"
#include <QPixmap>
#include <QtCore>
#include <QObject>
#include <qDebug>

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "emitterclass.h"

QByteArray image_buffer; //буфер со сканом купюры

char res[8] = "res.txt";
char res1[9] = "res1.txt";
char image[10] = "image.bmp";
//----------------------------------------------------------------------------------------------------
#pragma pack(1)
#pragma pack(1)
//Структура строки основного образа
typedef struct {
    WORD code;//код 0x5555
    WORD black;//уровень черного суммарно по 16 точкам
    BYTE data[1008];//данные CIS-a
    float tacho;//значение тахометра
    WORD left,right;//левая и правая границы, 0xFFFF если билета нет
    DWORD reserve;
} main_image_CIS;

struct bmpHeader{
    WORD	type;		// = 0x4D42
    DWORD	file_size;	//размер файла
    DWORD	reserve;	// = 0
    DWORD	offset;		// = 0x36 - смещение данных
    DWORD	size2;		// = 0x28 - размер 2-й структуры
    LONG	w;		//ширина
    LONG	h;		//высота
    WORD	planes;		// = 1, количество цветовых плоскостей
    WORD	bits;		// = 32, количество битов в пикселе
    DWORD	compres;	// = 0, тип сжатия
    DWORD	image_size;	//размер изображения в байтах
    LONG	p1, p2;		//доп. параметры = 0
    DWORD	p3, p4;		//доп. параметры = 0
};
#pragma pack()
bmpHeader header1 = {0x4D42, 0, 0, 0x36+1024, 0x28, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0};

BYTE bmp_palitra[1024];
//-------------------------------------------------------------------------------------------
/*/Запись буфера образа
void save_image(BYTE *buf_image,int adr_buf_image)
{
    FILE *bin,*bmp;
    DWORD CIS_len,i,image_hnum;
    int adr_max;
    image_CIS *buf_image_CIS;
    BYTE *buf,c;

    adr_max = adr_buf_image;
    printf("Save image ...\n");
    bin = fopen("image.bin","wb");
    fwrite(buf_image,adr_buf_image,1,bin);
    fclose(bin);
    printf("Save image.bin - O'k\n");
    CIS_len = CIS_DATA_LEN_ALL;
    for (i=0;i<255;i++) {
        buf = &bmp_palitra[i*4];
        buf[0] = buf[1] = buf[2] = (BYTE)i;
        buf[3] = 0;
    }
    buf = &bmp_palitra[255*4];
    buf[2] = 255;
    buf[1] = buf[0] = buf[3] = 0;

//	th = fopen("tacho.txt","wt");

    buf_image_CIS = (image_CIS*)buf_image;
    if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
        header1.w = CIS_len + 4 + 256;
    }
    else header1.w = CIS_len;
    image_hnum = adr_max/CIS_len;
    header1.h = image_hnum;
    header1.image_size = header1.h*header1.w;
    header1.file_size = header1.image_size + 0x36 + 1024;
    bmp = fopen("image.bmp","wb");
    if (bmp == NULL) return;
    fwrite(&header1,sizeof(header1),1,bmp);
    fwrite(bmp_palitra,1024,1,bmp);
    DWORD adr_work,s;
    adr_work = 0;
    for (s=0;s<image_hnum;s++) {
        buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
        if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
            int tach;
            int black = buf_image_CIS->mi.black / 16;
            fputc(0x55, bmp); fputc(0x55, bmp);
            for (i=0;i<14;i++) fputc(black, bmp);
            for (i=0;i<1008;i++) {
                c = buf_image_CIS->mi.data[i];
                if (c == 255) c = 254;
                if (i == buf_image_CIS->mi.left) c = 255;
                if (i == buf_image_CIS->mi.right) c = 255;
                fputc(c, bmp);
            }
            fputc(128, bmp); fputc(128, bmp); fputc(128, bmp); fputc(128, bmp);
            tach = (int)(128.0f * buf_image_CIS->mi.tacho);
            for (i=0;i<256;i++) {
                if (i == tach) fputc(255, bmp);
                else fputc(0, bmp);
            }
//			fprintf(th,"%08X\n",buf_image_CIS->mi.tacho);
        }
        else {//тестовый режим
            for (i=0;i<CIS_len;i++) {
                fputc(buf_image[adr_work+i], bmp);
            }
        }
        adr_work += CIS_len;
    }
    fclose(bmp);
//	fclose(th);
    printf("Save image.bmp - O'k\n");
    return;
}*/
//-------------------------------------------------------------------------------------------
//Запись буфера образа  // в буффер
void save_bmp(char *name,BYTE *buf,int w,int h)
{

    QBuffer buffer(&image_buffer);
    buffer.open(QIODevice::WriteOnly);



    FILE *bmp,*bin;
    int i;
    BYTE *bufp;
    main_image_CIS *buf_image_CIS;
    bin = fopen("image.bin","wb");
    fwrite(buf,1024*h,1,bin);
    fclose(bin);
    for (i=0;i<256;i++) {
        bufp = &bmp_palitra[i*4];
        bufp[0] = bufp[1] = bufp[2] = (BYTE)i;
        bufp[3] = 0;
    }
    header1.w = w;
    header1.h = h;
    header1.image_size = header1.h*header1.w;
    header1.file_size = header1.image_size + 0x36 + 1024;
    bmp = fopen(name,"wb");
    if (bmp == NULL) return;
    fwrite(&header1,sizeof(header1),1,bmp);
    fwrite(bmp_palitra,1024,1,bmp);
    buffer.write((char*)&header1,sizeof(header1));
    buffer.write((char*)bmp_palitra,sizeof(bmp_palitra));
    for (i=0;i<h;i++) {
        buf_image_CIS = (main_image_CIS *)(&buf[i*1024]);
        fwrite(buf_image_CIS->data,w,1,bmp);
        buffer.write((char*)buf_image_CIS->data,w);
    }
    fclose(bmp);
    return;
}
//-------------------------------------------------------------------------------------------
//сравнение 2-х файлов
void comp_2files(char *name1,char *name2)
{
    FILE *f1,*f2;
    size_t len1,len2;
    BYTE *buf1,*buf2;
    buf1 = buf2 = NULL;
    f1 = fopen(name1,"rb");
    if (!f1) {
        printf("ERROR file'%s' not found !!!!!!!!!!!!!\n",name1); return;
    }
    f2 = fopen(name2,"rb");
    if (!f2) {
        fclose(f1);
        printf("ERROR file'%s' not found !!!!!!!!!!!!!\n",name2); return;
    }
    fseek(f1,0,SEEK_END);
    len1 = ftell(f1);
    fseek(f1,0,SEEK_SET);
    fseek(f2,0,SEEK_END);
    len2 = ftell(f2);
    fseek(f2,0,SEEK_SET);
    if (len1 != len2) {
        printf("ERROR len comp res files: %d %d !!!!!!!!!!!!!!!!!!!!\n",len1,len2);
        goto end_all;
    }
    buf1 = new BYTE[len1];
    buf2 = new BYTE[len2];
    fread(buf1,len1,1,f1);
    fread(buf2,len2,1,f2);
    if (memcmp(buf1,buf2,len1)) {
        printf("ERROR comp res files !!!!!!!!!!!!!!!!!!!!\n");
    }

end_all:
    if (buf1) delete [] buf1;
    if (buf2) delete [] buf2;
    fclose(f1);
    fclose(f2);
}
//-------------------------------------------------------------------------------------------
//Функция запроса результатов тестирования
void get_res(void)
{
    int i,j,sum,sum_all;
    int size_res;
    FILE *out;
    BYTE buf_res[16*1024];
    ZeroMemory(buf_res,sizeof(buf_res));
    ScannerGetTicketInfo(buf_res,sizeof(buf_res),&size_res);
//	out = fopen("res.txt","wt");
//	fprintf(out,"%s\n",buf_res);
//	fclose(out);

    switch (buf_res[0]) {
    case 1://игровой купон
        out = fopen("res.txt","wt");
        fprintf(out,"Coupon  row/column = %d/%d  size = %d\n",buf_res[2],buf_res[3],size_res);
        printf("Coupon  row/column = %d/%d  size = %d\n",buf_res[2],buf_res[3],size_res);
        sum_all = 0;
        for (i=0;i<buf_res[2];i++) {
            BYTE b[16],b1,b2;
            sum = 0;
            b1 = buf_res[6+2*i]; b2 = buf_res[6+2*i+1];
            b[0] = b1&1 ? 1 : 0;
            b[1] = b1&2 ? 1 : 0;
            b[2] = b1&4 ? 1 : 0;
            b[3] = b1&8 ? 1 : 0;
            b[4] = b1&0x10 ? 1 : 0;
            b[5] = b1&0x20 ? 1 : 0;
            b[6] = b2&1 ? 1 : 0;
            b[7] = b2&2 ? 1 : 0;
            b[8] = b2&4 ? 1 : 0;
            b[9] = b2&8 ? 1 : 0;
            b[10] = b2&0x10 ? 1 : 0;
            b[11] = b2&0x20 ? 1 : 0;
            for (j=0;j<12;j++) {
                sum += b[j]; sum_all += b[j];
                fprintf(out,"%d ",b[j]);
                printf("%d ",b[j]);
            }
            fprintf(out,"Mark = %d\n",sum);
            printf("Mark = %d\n",sum);
        }
        fprintf(out,"Mark all = %d\n",sum_all);
        printf("Mark all = %d\n",sum_all);
        fclose(out);
        if (buf_res[1] < 2) printf("COUPON recognition quality = %d\n",buf_res[1]);//качество распознавания
        else printf("ERROR recognition quality = %d !!!!!!!!!!!!!!!!!!!!\n",buf_res[1]);
        comp_2files(res,res1);
        break;
    case 2://штрих код-ы
        out = fopen("res.txt","wt");
        printf("Bar-code num = %d  size = %d\n",buf_res[1],size_res);
        fprintf(out,"Bar-code num = %d  size = %d\n",buf_res[1],size_res);
        j = 2;
        for (i=0;i<buf_res[1];i++) {
            printf("Tip = %d  Len = %d\n",buf_res[j],buf_res[j+1]);
            fprintf(out,"Tip = %d  Len = %d\n",buf_res[j],buf_res[j+1]);
            int j1 = j + 2 + buf_res[j+1];
            for (j+=2;j<j1;j++) {
                printf("%c",buf_res[j]);
                fprintf(out,"%c",buf_res[j]);
            }
            printf("\n");
            fprintf(out,"\n");
        }
        fclose(out);
        break;
    default:
        out = fopen("res.txt","wt");
        printf("Code ticket = %d  size = %d\n",buf_res[0],size_res);
        fprintf(out,"Code ticket = %d  size = %d\n",buf_res[0],size_res);
        fclose(out);
    }
//запрос бинарного образа
    int w,h,buf_size;
    BYTE *buf_bin, *buf_test;
    ScannerGetScanDpi(&w,&h);
    printf("DPI w/h = %d/%d\n",w,h);
    ScannerGetOriginImageSize(&w,&h);
    printf("Image size w/h = %d/%d\n",w,h);
    if ((w!=0)&&(h!=0)) {
        buf_size = 1024 * h + 16;
        buf_bin = new BYTE[buf_size];
        int res = ScannerGetAllImage(buf_bin,buf_size);
        printf("ScannerGetAllImage result = %d\n",res);
        if (res == SUCCES_RESULT) {//вывод в .bmp файл
            save_bmp(image,buf_bin,w,h);
            printf("Save file 'image.bmp' - O'k\n");
        }
        delete[] buf_bin;
    }
    printf("\n");
}
//-------------------------------------------------------------------------------------------
#include "emitterclass.h"
EmitterClass a;
void call_back(int code_res,int code_ticket)
{
    printf("CallBack: res = %d  ticket = %d\n",code_res,code_ticket);
//	printf("CallBack: save 'res.txt'\n");
    if (code_res == SUCCES_RESULT) {
        get_res();

        a.ImageChangeFunction();
//		int res = ScannerRollBack();
//		if (res != SUCCES_RESULT) ScannerRollBack();
    }
    if (code_res == FATAL_ERROR_MECHANICS)
    {
        a.MechanicsErrorFunction();
    }
}

//-------------------------------------------------------------------------------------------
BOOL WINAPI HandlerRoutine(DWORD type)
{
    int state;
begin:
    switch (type) {
    case CTRL_C_EVENT:
    case CTRL_BREAK_EVENT:
    case CTRL_CLOSE_EVENT:
        state = ScannerDisable();
        switch (state) {
        case SCANNER_DISABLE:
        case SUCCES_RESULT:
            printf("ScannerDisable - O'k\n"); break;
        case FATAL_SCANNER_LOST:
            printf("ScannerDisable - Fatal error\n"); break;
        default:
            printf("ScannerDisable - ERROR code = %d\n",state);
            Sleep(500); goto begin;
        }
        break;
    default:
        break;
    }

    Sleep(1000);
    return FALSE;
}
//-------------------------------------------------------------------------------------------






























































































//////--------------------------------------------------------------------------------------------
//////Файл тестирования dll
//////--------------------------------------------------------------------------------------------
//#pragma once
//#pragma comment(lib,"libgosloto_new.lib")

//#define WIN32_LEAN_AND_MEAN
//#define _CRT_SECURE_NO_DEPRECATE
//#undef UNICODE


////#define _CRT_SECURE_NO_WARNINGS


//////--------------------------------------------------------------------------------------------
//#include <windows.h>
//#include <stdio.h>
//#include <process.h>
//#include "goslotolib.h"

//#include <QApplication>
//#include <QDebug>
//#include <QFile>
//#include <QMessageBox>

//////----------------------------------------------------------------------------------------------------
////#pragma pack(1)
////#pragma pack(1)
////Структура строки основного образа
//typedef struct {
//    WORD code;//код 0x5555
//    WORD black;//уровень черного суммарно по 16 точкам
//    BYTE data[1008];//данные CIS-a
//    float tacho;//значение тахометра
//    WORD left,right;//левая и правая границы, 0xFFFF если билета нет
//    DWORD reserve;
//} main_image_CIS;

//struct bmpHeader{
//    WORD	type;		// = 0x4D42
//    DWORD	file_size;	//размер файла
//    DWORD	reserve;	// = 0
//    DWORD	offset;		// = 0x36 - смещение данных
//    DWORD	size2;		// = 0x28 - размер 2-й структуры
//    LONG	w;		//ширина
//    LONG	h;		//высота
//    WORD	planes;		// = 1, количество цветовых плоскостей
//    WORD	bits;		// = 32, количество битов в пикселе
//    DWORD	compres;	// = 0, тип сжатия
//    DWORD	image_size;	//размер изображения в байтах
//    LONG	p1, p2;		//доп. параметры = 0
//    DWORD	p3, p4;		//доп. параметры = 0
//};
//#pragma pack()
//bmpHeader header1 = {0x4D42, 0, 0, 0x36+1024, 0x28, 0, 0, 1, 8, 0, 0, 0, 0, 0, 0};

//BYTE bmp_palitra[1024];
////-------------------------------------------------------------------------------------------
///*/Запись буфера образа
//void save_image(BYTE *buf_image,int adr_buf_image)
//{
//    FILE *bin,*bmp;
//    DWORD CIS_len,i,image_hnum;
//    int adr_max;
//    image_CIS *buf_image_CIS;
//    BYTE *buf,c;

//    adr_max = adr_buf_image;
//    printf("Save image ...\n");
//    bin = fopen("image.bin","wb");
//    fwrite(buf_image,adr_buf_image,1,bin);
//    fclose(bin);
//    printf("Save image.bin - O'k\n");
//    CIS_len = CIS_DATA_LEN_ALL;
//    for (i=0;i<255;i++) {
//        buf = &bmp_palitra[i*4];
//        buf[0] = buf[1] = buf[2] = (BYTE)i;
//        buf[3] = 0;
//    }
//    buf = &bmp_palitra[255*4];
//    buf[2] = 255;
//    buf[1] = buf[0] = buf[3] = 0;

////	th = fopen("tacho.txt","wt");

//    buf_image_CIS = (image_CIS*)buf_image;
//    if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
//        header1.w = CIS_len + 4 + 256;
//    }
//    else header1.w = CIS_len;
//    image_hnum = adr_max/CIS_len;
//    header1.h = image_hnum;
//    header1.image_size = header1.h*header1.w;
//    header1.file_size = header1.image_size + 0x36 + 1024;
//    bmp = fopen("image.bmp","wb");
//    if (bmp == NULL) return;
//    fwrite(&header1,sizeof(header1),1,bmp);
//    fwrite(bmp_palitra,1024,1,bmp);
//    DWORD adr_work,s;
//    adr_work = 0;
//    for (s=0;s<image_hnum;s++) {
//        buf_image_CIS = (image_CIS*)(&buf_image[adr_work]);
//        if (buf_image_CIS->mi.code == 0x5555) {//рабочий режим
//            int tach;
//            int black = buf_image_CIS->mi.black / 16;
//            fputc(0x55, bmp); fputc(0x55, bmp);
//            for (i=0;i<14;i++) fputc(black, bmp);
//            for (i=0;i<1008;i++) {
//                c = buf_image_CIS->mi.data[i];
//                if (c == 255) c = 254;
//                if (i == buf_image_CIS->mi.left) c = 255;
//                if (i == buf_image_CIS->mi.right) c = 255;
//                fputc(c, bmp);
//            }
//            fputc(128, bmp); fputc(128, bmp); fputc(128, bmp); fputc(128, bmp);
//            tach = (int)(128.0f * buf_image_CIS->mi.tacho);
//            for (i=0;i<256;i++) {
//                if (i == tach) fputc(255, bmp);
//                else fputc(0, bmp);
//            }
////			fprintf(th,"%08X\n",buf_image_CIS->mi.tacho);
//        }
//        else {//тестовый режим
//            for (i=0;i<CIS_len;i++) {
//                fputc(buf_image[adr_work+i], bmp);
//            }
//        }
//        adr_work += CIS_len;
//    }
//    fclose(bmp);
////	fclose(th);
//    printf("Save image.bmp - O'k\n");
//    return;
//}*/
////-------------------------------------------------------------------------------------------
////Запись буфера образа
//void save_bmp(char *name,BYTE *buf,int w,int h)
//{
//    FILE *bmp,*bin;
//    int i;
//    BYTE *bufp;
//    int bufer = 7;
//    QByteArray bufff;
//    main_image_CIS *buf_image_CIS;
//    //fopen_s(&bmp,name,"r");
//    bin = fopen("image.bin","wb");
//    fwrite(buf,1024*h,1,bin);
//    fclose(bin);



////    QString str;
////    QFile file("image.bin");
////    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
////    {
////        qDebug() << "Нe удается открыть файл.";
////    }
////    QByteArray ba = QByteArray::fromRawData(reinterpret_cast <const char*>(buf),h*w);
////    QDataStream stream(&file); //QTextStream
////    //str(QByteArray(buf,h*w));
////    //str.sprintf("%s",buf);
////    stream << ba;
////    file.close();


//    for (i=0;i<256;i++) {
//        bufp = &bmp_palitra[i*4];
//        bufp[0] = bufp[1] = bufp[2] = (BYTE)i;
//        bufp[3] = 0;
//    }
//    header1.w = w;
//    header1.h = h;
//    header1.image_size = header1.h*header1.w;
//    header1.file_size = header1.image_size + 0x36 + 1024;
//    bmp = fopen(name,"wb");
//    //fopen_s(&bmp,name,"r");
//    if (bmp == NULL) return;
//    fwrite(&header1,sizeof(header1),1,bmp);
//    fwrite(bmp_palitra,1024,1,bmp);
//    for (i=0;i<h;i++) {
//        buf_image_CIS = (main_image_CIS *)(&buf[i*1024]);
//        fwrite(buf_image_CIS->data,w,1,bmp);
//    }
//    fclose(bmp);



////    QFile image(name);
////    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
////    {
////        qDebug() << "Нe удается открыть файл.";
////    }
////    QDataStream stream2(&file); //QTextStream
////    QByteArray ba1 = QByteArray::fromRawData(reinterpret_cast <const char*>(&header1),sizeof(header1));
////    QByteArray ba2 = QByteArray::fromRawData(reinterpret_cast <const char*>(bmp_palitra),1024);
////    stream << ba1 <<ba2;
////    for (i=0;i<h;i++) {
////            buf_image_CIS = (main_image_CIS *)(&buf[i*1024]);
////            QByteArray ba3 = QByteArray::fromRawData(reinterpret_cast <const char*>(buf_image_CIS),w);
////            stream << ba3;
////    }

////    file.close();






//    return;
//}
////-------------------------------------------------------------------------------------------



////сравнение 2-х файлов
//void comp_2files(char *name1,char *name2)
//{
//    QString str;
//    FILE *f1,*f2;
//    size_t len1,len2;
//    BYTE *buf1,*buf2;
//    buf1 = buf2 = NULL;
//    f1 = fopen(name1,"rb");
//    if (!f1) {
//        str.sprintf("ERROR file'%s' not found !!!!!!!!!!!!!\n",name1);
//        qDebug() << str;
//        return;
//    }
//    f2 = fopen(name2,"rb");
//    if (!f2) {
//        fclose(f1);
//        str.sprintf("ERROR file'%s' not found !!!!!!!!!!!!!\n",name2);
//        qDebug() << str ;
//        return;
//    }
//    fseek(f1,0,SEEK_END);
//    len1 = ftell(f1);
//    fseek(f1,0,SEEK_SET);
//    fseek(f2,0,SEEK_END);
//    len2 = ftell(f2);
//    fseek(f2,0,SEEK_SET);
//    if (len1 != len2) {
//        str.sprintf("ERROR len comp res files: %d %d !!!!!!!!!!!!!!!!!!!!\n",len1,len2);
//        qDebug() << str ;
//        goto end_all;
//    }
//    buf1 = new BYTE[len1];
//    buf2 = new BYTE[len2];
//    fread(buf1,len1,1,f1);
//    fread(buf2,len2,1,f2);
//    if (memcmp(buf1,buf2,len1)) {
//        str.sprintf("ERROR comp res files !!!!!!!!!!!!!!!!!!!!\n");
//        qDebug() << str ;
//    }

//end_all:
//    if (buf1) delete [] buf1;
//    if (buf2) delete [] buf2;
//    fclose(f1);
//    fclose(f2);
//}
//////-------------------------------------------------------------------------------------------

//char res[] = "res.txt";
//char res1[] = "res1.txt";
//char image[] = "image.bmp";
////Функция запроса результатов тестирования
//void get_res(void)
//{
//    int i,j,sum,sum_all;
//    int size_res;
//    FILE *out;
//    BYTE buf_res[16*1024];
//    qDebug() << buf_res;
//    ZeroMemory(buf_res,sizeof(buf_res));
//    ScannerGetTicketInfo(buf_res,sizeof(buf_res),&size_res);
////    out = fopen("res.txt","wt");
////    fprintf(out,"%s\n",buf_res);
////    fclose(out);

//    QFile file("res.txt");
//    if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    {
//        qDebug() << "Не удается открыть файл.";
//    }

//    QTextStream stream(&file);
//    stream << buf_res;
//    file.close();


//    switch (buf_res[0]) {
//    case 1://игровой купон
//        out = fopen("res.txt","wt");
//        fprintf(out,"Coupon  row/column = %d/%d  size = %d\n",buf_res[2],buf_res[3],size_res);
//        printf("Coupon  row/column = %d/%d  size = %d\n",buf_res[2],buf_res[3],size_res);
//        sum_all = 0;
//        for (i=0;i<buf_res[2];i++) {
//            BYTE b[16],b1,b2;
//            sum = 0;
//            b1 = buf_res[6+2*i]; b2 = buf_res[6+2*i+1];
//            b[0] = b1&1 ? 1 : 0;
//            b[1] = b1&2 ? 1 : 0;
//            b[2] = b1&4 ? 1 : 0;
//            b[3] = b1&8 ? 1 : 0;
//            b[4] = b1&0x10 ? 1 : 0;
//            b[5] = b1&0x20 ? 1 : 0;
//            b[6] = b2&1 ? 1 : 0;
//            b[7] = b2&2 ? 1 : 0;
//            b[8] = b2&4 ? 1 : 0;
//            b[9] = b2&8 ? 1 : 0;
//            b[10] = b2&0x10 ? 1 : 0;
//            b[11] = b2&0x20 ? 1 : 0;
//            for (j=0;j<12;j++) {
//                sum += b[j]; sum_all += b[j];
//                fprintf(out,"%d ",b[j]);
//                printf("%d ",b[j]);
//            }
//            fprintf(out,"Mark = %d\n",sum);
//            printf("Mark = %d\n",sum);
//        }
//        fprintf(out,"Mark all = %d\n",sum_all);
//        printf("Mark all = %d\n",sum_all);
//        fclose(out);
//        if (buf_res[1] < 2) printf("COUPON recognition quality = %d\n",buf_res[1]);//качество распознавания
//        else printf("ERROR recognition quality = %d !!!!!!!!!!!!!!!!!!!!\n",buf_res[1]);
//        comp_2files(res,res1);
//        break;
//    case 2://штрих код-ы
//        out = fopen("res.txt","wt");
//        printf("Bar-code num = %d  size = %d\n",buf_res[1],size_res);
//        fprintf(out,"Bar-code num = %d  size = %d\n",buf_res[1],size_res);
//        j = 2;
//        for (i=0;i<buf_res[1];i++) {
//            printf("Tip = %d  Len = %d\n",buf_res[j],buf_res[j+1]);
//            fprintf(out,"Tip = %d  Len = %d\n",buf_res[j],buf_res[j+1]);
//            int j1 = j + 2 + buf_res[j+1];
//            for (j+=2;j<j1;j++) {
//                printf("%c",buf_res[j]);
//                fprintf(out,"%c",buf_res[j]);
//            }
//            printf("\n");
//            fprintf(out,"\n");
//        }
//        fclose(out);
//        break;
//    default:
//        QString str;

//        QFile file("res.txt");
//        if  (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//        {
//            qDebug() << "Нe удается открыть файл.";
//        }

//        QTextStream stream(&file);
//        str.sprintf("Code ticket = %d  size = %d/n",buf_res[0],size_res);
//        stream << str;
//        file.close();

////        out = fopen("res.txt","wt");
////        fprintf(out,"Code ticket = %d  size = %d/n",buf_res[0],size_res);
//        str.sprintf("Code ticket = %d  size = %d/n",buf_res[0],size_res);
//        qDebug() << str;
////        fclose(out);
//    }
////запрос бинарного образа
//    int w,h,buf_size;
//    BYTE *buf_bin;
//    QString str;
//    ScannerGetScanDpi(&w,&h);
//    str.sprintf("DPI w/h = %d/%d/n",w,h);
//    qDebug() << str;

//    ScannerGetOriginImageSize(&w,&h);
//    str.sprintf("Image size w/h = %d/%d/n",w,h);
//    qDebug() << str;
//    if ((w!=0)&&(h!=0)) {
//        buf_size = 1024 * h + 16;
//        buf_bin = new BYTE[buf_size];
//        int res = ScannerGetAllImage(buf_bin,buf_size);
//        str.sprintf("ScannerGetAllImage result = %d//n",res);
//        qDebug() << str;
//        if (res == SUCCES_RESULT) {//вывод в .bmp файл
//            save_bmp(image,buf_bin,w,h);
//            str.sprintf("Save file 'image.bmp' - O'k//n");
//            qDebug() << str;
//        }
//        delete[] buf_bin;
//    }
//    str.sprintf("/n");
//    qDebug() << str;
//}
////-------------------------------------------------------------------------------------------
//void call_back(int code_res,int code_ticket)
//{
//    QString str;
//    str.sprintf("CallBack: res = %d  ticket = %d/n",code_res,code_ticket);
//    qDebug() << str;
////	printf("CallBack: save 'res.txt'\n");
//    if (code_res == SUCCES_RESULT) {
//        get_res();
////		int res = ScannerRollBack();
////		if (res != SUCCES_RESULT) ScannerRollBack();
//    }
//}
//////-------------------------------------------------------------------------------------------
//BOOL WINAPI HandlerRoutine(DWORD type)
//{
//    QString str;
//    int state;
//begin:
//    switch (type) {
//    case CTRL_C_EVENT:
//    case CTRL_BREAK_EVENT:
//    case CTRL_CLOSE_EVENT:
//        state = ScannerDisable();
//        switch (state) {
//        case SCANNER_DISABLE:
//        case SUCCES_RESULT:
//            str.sprintf("ScannerDisable - O'k\n");
//            qDebug() << str;
//            break;
//        case FATAL_SCANNER_LOST:
//            str.sprintf("ScannerDisable - Fatal error\n");
//            qDebug() << str;
//            break;
//        default:
//            str.sprintf("ScannerDisable - ERROR code = %d\n",state);
//            qDebug() << str;
//            Sleep(500); goto begin;
//        }
//        break;
//    default:
//        break;
//    }

//    Sleep(1000);
//    return FALSE;
//}
