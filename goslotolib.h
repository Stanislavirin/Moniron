//--------------------------------------------------------------------------------------------
//Файл экспорта API для Гослото
//--------------------------------------------------------------------------------------------
#ifndef _GOSLOTOLIB_H_
#define _GOSLOTOLIB_H_

#ifdef __DLL__
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif
//--------------------------------------------------------------------------------------------
//Коды ошибок
//--------------------------------------------------------------------------------------------
#define SUCCES_RESULT (0)//успешное выполнение
#define SCANNER_NOT_READY (1)//сканер не готов к работе
#define SCANNING_NOT_COMPLETED (2)//сканирование не завершено
#define FATAL_SCANNER_NOT_FOUND (3)//сканер не подключен
#define SCANNING_ALREADY_GOES (4)//сканирование уже идет
#define FATAL_ERROR_SPEED (5)//не настроена скорость прокрутки
#define FATAL_ERROR_MECHANICS (6)//заклинило механику
#define FATAL_SCANNER_LOST (7)//связь со сканером потеряна
#define SCANNER_DISABLE (8)//сканер отключен
#define SCANNING_TICKET_GOES (9)//идет сканирование документа
#define ERROR_DELTA_LEVEL_COUPON (10)//смещение порога за пределами допустимого
#define SCANNER_NOT_ROLLBACK (11)//режим обратной прокрутки не поддерживается сканером !!!!!!!!!!!!
#define SCANNER_TEST (12)//сканер в режиме самотестирония
//--------------------------------------------------------------------------------------------
#define MAX_DELTA_LEVEL_COUPON (16)//предел смещения порога обработки
//--------------------------------------------------------------------------------------------
//Типы данных
//--------------------------------------------------------------------------------------------
//Тип функции обратного вызова, code_res - код ошибки или успешного выполнения, code_ticket - код документа
typedef void (*SCANNERCALLBACK)(int code_res,int code_ticket);
void call_back(int code_res,int code_ticket);
//--------------------------------------------------------------------------------------------
//Экспортируемые функции
//--------------------------------------------------------------------------------------------
//инициализация сканера
extern "C" int DLL_EXPORT ScannerInit(SCANNERCALLBACK scannerCallBack,int delta_level);
//проверка готовности сканера к работе
extern "C" int DLL_EXPORT ScannerIsReady(void);
//отключение от сканера
extern "C" int DLL_EXPORT ScannerDisable(void);
//возвращает версию прошивки сканера
extern "C" unsigned int DLL_EXPORT ScannerGetHWVersion(void);
//возвращает код последней ошибки
extern "C" int DLL_EXPORT ScannerGetLastErrorCode(void);
//возвращает последнюю ошибку в виде строки на английском языке
extern "C" const char DLL_EXPORT *ScannerGetLastErrorStr(void);
//аварийное прерывание сканирования
extern "C" int DLL_EXPORT ScannerStop(void);
//проверка завершения сканирования
extern "C" int DLL_EXPORT ScannerIsComplete(void);
//обратное прокручивание бумаги - заглушка, не поддерживается сканером !!!!!!!!!!!!!!!!!
extern "C" int DLL_EXPORT ScannerRollBack(void);
//получение информации о сканируемом документе
extern "C" int DLL_EXPORT ScannerGetTicketInfo(unsigned char *ticketInfo, int size, int *data_size);
//получение информации о разрешении сканера
extern "C" void DLL_EXPORT ScannerGetScanDpi(int *widthDpi, int *heightDpi);
//получение информации о размере отсканированного изображения
extern "C" void DLL_EXPORT ScannerGetOriginImageSize(int *width, int *height);
//получение информации о глубине цвета
extern "C" void DLL_EXPORT ScannerGetOriginImageBPP(unsigned short *bpp);
//выдача изображения в виде битовой матрицы
extern "C" int DLL_EXPORT ScannerGetOriginImage(unsigned char *image, int size);
//выдача текстового идентификатора сканера
extern "C" const char DLL_EXPORT *ScannerGetScannerID(void);
//выдача изображения с дополниельными данными
extern "C" int DLL_EXPORT ScannerGetAllImage(unsigned char *image, int size);
//--------------------------------------------------------------------------------------------

#endif
