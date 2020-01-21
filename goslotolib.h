//--------------------------------------------------------------------------------------------
//���� �������� API ��� �������
//--------------------------------------------------------------------------------------------
#ifndef _GOSLOTOLIB_H_
#define _GOSLOTOLIB_H_

#ifdef __DLL__
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
//--------------------------------------------------------------------------------------------
//���� ������
//--------------------------------------------------------------------------------------------
#define SUCCES_RESULT (0)//�������� ����������
#define SCANNER_NOT_READY (1)//������ �� ����� � ������
#define SCANNING_NOT_COMPLETED (2)//������������ �� ���������
#define FATAL_SCANNER_NOT_FOUND (3)//������ �� ���������
#define SCANNING_ALREADY_GOES (4)//������������ ��� ����
#define FATAL_ERROR_SPEED (5)//�� ��������� �������� ���������
#define FATAL_ERROR_MECHANICS (6)//��������� ��������
#define FATAL_SCANNER_LOST (7)//����� �� �������� ��������
#define SCANNER_DISABLE (8)//������ ��������
#define SCANNING_TICKET_GOES (9)//���� ������������ ���������
#define ERROR_DELTA_LEVEL_COUPON (10)//�������� ������ �� ��������� �����������
#define SCANNER_NOT_ROLLBACK (11)//����� �������� ��������� �� �������������� �������� !!!!!!!!!!!!
#define SCANNER_TEST (12)//������ � ������ ��������������
//--------------------------------------------------------------------------------------------
#define MAX_DELTA_LEVEL_COUPON (16)//������ �������� ������ ���������
//--------------------------------------------------------------------------------------------
//���� ������
//--------------------------------------------------------------------------------------------
//��� ������� ��������� ������, code_res - ��� ������ ��� ��������� ����������, code_ticket - ��� ���������
typedef void (*SCANNERCALLBACK)(int code_res,int code_ticket);
void call_back(int code_res,int code_ticket);
//--------------------------------------------------------------------------------------------
//�������������� �������
//--------------------------------------------------------------------------------------------
//������������� �������
extern "C" int DLL_EXPORT ScannerInit(SCANNERCALLBACK scannerCallBack,int delta_level);
//�������� ���������� ������� � ������
extern "C" int DLL_EXPORT ScannerIsReady(void);
//���������� �� �������
extern "C" int DLL_EXPORT ScannerDisable(void);
//���������� ������ �������� �������
extern "C" unsigned int DLL_EXPORT ScannerGetHWVersion(void);
//���������� ��� ��������� ������
extern "C" int DLL_EXPORT ScannerGetLastErrorCode(void);
//���������� ��������� ������ � ���� ������ �� ���������� �����
extern "C" const char DLL_EXPORT *ScannerGetLastErrorStr(void);
//��������� ���������� ������������
extern "C" int DLL_EXPORT ScannerStop(void);
//�������� ���������� ������������
extern "C" int DLL_EXPORT ScannerIsComplete(void);
//�������� ������������� ������ - ��������, �� �������������� �������� !!!!!!!!!!!!!!!!!
extern "C" int DLL_EXPORT ScannerRollBack(void);
//��������� ���������� � ����������� ���������
extern "C" int DLL_EXPORT ScannerGetTicketInfo(unsigned char *ticketInfo, int size, int *data_size);
//��������� ���������� � ���������� �������
extern "C" void DLL_EXPORT ScannerGetScanDpi(int *widthDpi, int *heightDpi);
//��������� ���������� � ������� ���������������� �����������
extern "C" void DLL_EXPORT ScannerGetOriginImageSize(int *width, int *height);
//��������� ���������� � ������� �����
extern "C" void DLL_EXPORT ScannerGetOriginImageBPP(unsigned short *bpp);
//������ ����������� � ���� ������� �������
extern "C" int DLL_EXPORT ScannerGetOriginImage(unsigned char *image, int size);
//������ ���������� �������������� �������
extern "C" const char DLL_EXPORT *ScannerGetScannerID(void);
//������ ����������� � �������������� �������
extern "C" int DLL_EXPORT ScannerGetAllImage(unsigned char *image, int size);
//--------------------------------------------------------------------------------------------

#endif
