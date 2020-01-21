#include "tesseract_class.h"

//tesseract_class::tesseract_class()
//{

//        // initilize tesseract OCR engine
//          tesseract::TessBaseAPI *myOCR =
//            new tesseract::TessBaseAPI();

//          printf("Tesseract-ocr version: %s\n",
//                 myOCR->Version());
//          // printf("Leptonica version: %s\n",
//          //        getLeptonicaVersion());

//          if (myOCR->Init(NULL, "rus")) {
//            fprintf(stderr, "Could not initialize tesseract.\n");
//            exit(1);
//          }

//          tesseract::PageSegMode pagesegmode = static_cast<tesseract::PageSegMode>(7); // treat the image as a single text line
//          myOCR->SetPageSegMode(pagesegmode);

//          // read iamge
//          namedWindow("tesseract-opencv", 0);
//          Mat image = imread("C:\\Stas\\desintagrator_pro\\1\\MonironExpertS\\sample.png", 0);


//          // set region of interest (ROI), i.e. regions that contain text
//          Rect text1ROI(0, 0, 266, 80);


//          // recognize text
//          myOCR->TesseractRect( image.data, 1, image.step1(), text1ROI.x, text1ROI.y, text1ROI.width, text1ROI.height);
//          const char *text1 = myOCR->GetUTF8Text();

//          // remove "newline"
//          string t1(text1);
//          t1.erase(std::remove(t1.begin(), t1.end(), '\n'), t1.end());


//          // print found text
//          printf("found text1: \n");
//          printf(t1.c_str());
//          printf("\n");



//          QString filename = "test.txt";
//                            //C:\Stas\desintagrator_pro\1\MonironExpertS\tests
//          QFile file1(filename);
//          if  (!file1.open(QIODevice::WriteOnly | QIODevice::Text))
//          {
//              qDebug() << "Не удалось открыть файл";
//          }
//          QTextStream stream(&file1);
//          QString sss;

//          sss=QString::fromStdString(t1);


//          stream << sss;
//          file1.close();


//    //        //Конвертирование кодировки в UTF-8
//    //        QString str,utf8Str; //только номера
//    //        str=QString::fromStdString(t1);
//    //        QByteArray ba;
//    //        QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
//    //        ba=str.toUtf8();
//    //        utf8Str = codec->toUnicode(ba);

//    //            QTextCodec* defaultTextCodec = QTextCodec::codecForName("Windows-1251");


//    //        qDebug() << t1.c_str();




//          // draw text on original image
//          Mat scratch = imread("C:\\Stas\\desintagrator_pro\\1\\MonironExpertS\\sample.png");

//          int fontFace = FONT_HERSHEY_PLAIN;
//          double fontScale = 2;
//          int thickness = 2;
//          putText(scratch, t1, Point(text1ROI.x, text1ROI.y), fontFace, fontScale, Scalar(0, 255, 0), thickness, 8);
//          rectangle(scratch, text1ROI, Scalar(0, 0, 255), 2, 8, 0);


//          imshow("tesseract-opencv", scratch);
//          waitKey(0);

//          delete [] text1;


//          // destroy tesseract OCR engine
//          myOCR->Clear();
//          myOCR->End();
//}
