#include "rotate_help.h"
#include <QDebug>
const int N=110;

int threshold11=33, threshold22=55; // пороги для определения границ купюры


// находим среднее арифметическое в области яркости (x1,y1) - (x2,y2)
double get_arithmetic_mean(int x1, int y1, int x2, int y2, cv::Mat canny_mat)
{
    double res=0;
    if (canny_mat.cols<x2) x2=canny_mat.cols;
    for (int i=x1;i<x2;i++)
    {
        for (int j=y1;j<y2;j++)
        {
            res+=canny_mat.at<uchar>(cv::Point(i,j));
        }
    }
    return res/((x2-x1)*(y2-y1));
}

//находим усредненное отстояние границы купюры от левого края изображения
int get_image_left_offcet_x(cv::Mat canny_mat)
{
    int y=50;
    int res=0;
    for (int i=0;i<N;i++)
    {
        for (int j=10;j<canny_mat.cols; j++)
        {
            if ( canny_mat.at<uchar>(cv::Point(j,y)) > 0 )
            {
                res+=j;
                y+=4;
                break;
            }
        }
    }
    return res/=(N);
}
//находим усредненное отстояние границы купюры от верхнего края изображения
int get_image_top_offcet_y(cv::Mat canny_mat)
{
    int x=100;
    int res=0;
    for (int i=0;i<N;i++)
    {
        for (int j=10;j<canny_mat.rows; j++)
        {
            if ( canny_mat.at<uchar>(cv::Point(x,j)) > 0 )
            {
                res+=j;
                x+=10;
                break;
            }
        }
    }
    return res/=N;
}


//находим усредненное отстояние границы купюры от правого края изображения
int get_image_right_offcet_x(cv::Mat canny_mat)
{
    int y=50;
    int res=0;
    for (int i=0;i<N;i++)
    {
        for (int j=canny_mat.cols-10;j>0; j--)
        {
            if ( canny_mat.at<uchar>(cv::Point(j,y)) > 0 )
            {
                res+=j;
                y+=4;
                break;
            }
        }
    }
    return res/=(N);
}
//находим усредненное отстояние границы купюры от нижнего края изображения
int get_image_bot_offcet_y(cv::Mat canny_mat)
{
    int x=70;
    int res=0;
    for (int i=0;i<N;i++)
    {
        for (int j=canny_mat.rows-10;j>0; j--)
        {
            if ( canny_mat.at<uchar>(cv::Point(x,j)) > 0 )
            {
                res+=j;
                x+=10;
                break;
            }
        }
    }
    return res/=N;
}




static int jjj=0;
//Заполняем массивы x_array, y_array , в которых хранятся координаты точек границы купюры(по которым в дальнейшем будет производиться разворот)
void get_point_xy(int* x_array, int* y_array, int y_num, cv::Mat canny_mat)
{
    for (int i=5; i<canny_mat.cols-5; i++)
    {
        if ( canny_mat.at<uchar>(cv::Point(i,y_num)) > 0 )
        {
            if ((i-(x_array[jjj-1]) > 5) & (jjj>2))
            {
               // скорее всего ошибка в определении границ, этот пиксель не учитываем
                x_array[jjj]=x_array[jjj-1];
                y_array[jjj]=y_num;
                jjj++;
                break;
            }
            else
            {
                x_array[jjj]=i;
                y_array[jjj]=y_num;
                jjj++;
                break;
            }
        }
    }
}

//на вход массив чисел array[], число элементов массива
//на выходе сумма элементов массива
double sum(int* array,int n)
{
    double res=0;
    for (int i=0; i<n; i++)
    {
        res+=array[i];
    }
    return res;
}

//подсчет переменных a и b по методу МНК
//на вход: a-a,b-b, x_array- массив Х координат точек, y_array- массив Y кординат точек, N - кол-во точек
void mnk(double& a,double& b, int* x_array, int* y_array, int n)
{
    double top_a, bot_a, top_b, bot_b;

    //Находим n*(sum(xi*yi));
    int xy_array[N];
    for (int i=0;i<n; i++)
    {
        xy_array[i] = x_array[i]*y_array[i];
    }

    top_a = n*sum(xy_array,n) - sum(x_array,n)*sum(y_array,n);



    int xx_array[N];
    for (int i=0;i<n; i++)
    {
        xx_array[i] = x_array[i]*x_array[i];
    }

    bot_a = (n)*sum(xx_array,n) - sum(x_array,n)*sum(x_array,n);
    if (bot_a==0)
        qDebug()<<"error ,bot_a = 0";
    a=top_a/bot_a;


    b=(sum(y_array,n)-a*sum(x_array,n))/(n);

}

const int image_scale_factor = 0.1;       // 1.0 - 100% изображения
using namespace cv;
using namespace std;

void CropBillFromScan(cv::Mat &src, cv::Mat &dest)
{
//    static const std::string kWinName1 = "1 Входной скан ";
//    namedWindow(kWinName1,cv::WINDOW_NORMAL);
//    imshow(kWinName1, src);

    // изменение размера изображения
    cv::Mat image;
    image.resize(image_scale_factor);
    //перевод изображения в Ч\Б
    cv::Mat image_gray;
    cv::cvtColor( src, image_gray, cv::IMREAD_GRAYSCALE );
    //размывание, чтобы скрыть мелкие детали (иначе они будут ошибочно приняты за конутры)
    cv::Mat image_prepared;
    GaussianBlur( image_gray, image_prepared, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );

//    static const std::string kWinName2 = "2";
//    namedWindow(kWinName2,cv::WINDOW_NORMAL);
//    imshow(kWinName2, image_prepared);

    //кенни
    cv::Mat canny_mat;
    cv::Canny(image_prepared, canny_mat, threshold11, threshold22, 3);
    static const std::string kWinName3 = "3 Canny";
    namedWindow(kWinName3,cv::WINDOW_GUI_NORMAL);
    imshow(kWinName3, canny_mat);

//    static const std::string kWinName3 = "3 Canny";
//    namedWindow(kWinName3,cv::WINDOW_GUI_NORMAL);
//    cv::createTrackbar("treshold1",kWinName3,&threshold11,255);
//    cv::createTrackbar("treshold2",kWinName3,&threshold22,255);
//    while (1)
//    {
//        cv::Canny(image_prepared, canny_mat, threshold11, threshold22, 3);
//        imshow(kWinName3, canny_mat);
//        cv::waitKey(-1);
//    }




    //cv::Mat canny_output;
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(canny_mat,contours,hierarchy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE,cv::Point(0, 0));


    //cv::cvtColor( canny_mat, canny_mat, cv::IMREAD_COLOR );

//    int largest_contour_index=0;
//    int largest_area=0;
//    Rect bounding_rect;
//    for( int i = 0; i< contours.size(); i++ )
//        {
//            //  Find the area of contour
//            double a=contourArea( contours[i],false);
//            if(a>largest_area){
//                largest_area=a;cout<<i<<" area  "<<a<<endl;
//                // Store the index of largest contour
//                largest_contour_index=i;
//                // Find the bounding rectangle for biggest contour
//                bounding_rect=boundingRect(contours[i]);
//            }
//        }
//        Scalar color( 255,255,255);  // color of the contour in the
//        //Draw the contour and rectangle
//        drawContours( canny_mat, contours,largest_contour_index, color, cv::FILLED,8,hierarchy);
//        rectangle(canny_mat, bounding_rect,  Scalar(0,255,0),5, 8,0);





    //Draw contours
    cv::Mat drawing = cv::Mat::zeros( canny_mat.size(), CV_8UC3 );
    RNG rng(12345);
    for( int i = 0; i< contours.size(); i++ )
       {
         Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
         drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
       }



    /// Show in a window
    namedWindow( "Contours", cv::WINDOW_AUTOSIZE );
    imshow( "4 Contours", drawing );



}


cv::Mat turnTheMatAndCashCrop(cv::Mat &src)
{
    static int h=47;
//    h++;
//    char k[] = "1";
//    k[0]=h;
//    char* source_window = k;
//    namedWindow( source_window, cv::BORDER_DEFAULT );
//    imshow(source_window, src);
//    h++;


    cv::Mat src_extended((src.rows+30),(src.cols+30),src.type(),cv::Scalar(0,0,0));
    cv::cvtColor( src, src, cv::COLOR_RGBA2GRAY );
    cv::cvtColor( src_extended, src_extended, cv::COLOR_RGBA2GRAY );

    cv::Rect myROI3(cv::Point(0, 0), cv::Point((src.cols),(src.rows)));
    src.copyTo(src_extended(myROI3));

//    h++;
//    char n[] = "1";
//    n[0]=h;
//    char* source__extended_window = n;
//    namedWindow( source__extended_window, cv::BORDER_DEFAULT );
//    imshow(source__extended_window, src_extended);
//    h++;
//    cv::waitKey(-1);



    cv::Mat src_wrapped;
    int threshold11=50, threshold22=100; // пороги для определения границ купюры
    cv::Mat src_extended_gray;
    cv::Mat canny_mat1,canny_mat2,canny_mat_color_wrapped,canny_mat_wrapped;
    GaussianBlur( src_extended, src_extended, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT );
    // Convert it to gray
    cv::cvtColor( src_extended, src_extended_gray, cv::IMREAD_GRAYSCALE );
    cv::Canny(src_extended_gray, canny_mat1, threshold11, threshold22, 3);

//    h++;
//    char o[] = "1";
//    char* src_gray_window = o;
//    namedWindow( src_gray_window, cv::BORDER_DEFAULT );
//    imshow(src_gray_window, src_extended_gray);
//    h++;
//    cv::waitKey(-1);


//    char m[] = "1";
//    m[0]=h;
//    char* canny_window = m;
//    namedWindow( canny_window, cv::BORDER_DEFAULT );
//    h++;
//    imshow(canny_window, canny_mat1);
//    cv::waitKey(-1);




//    cv::createTrackbar("Threshold11",canny_window,&threshold11,255,0,0);
//    cv::createTrackbar("Threshold22",canny_window,&threshold22,255,0,0);

//    while (1)
//    {


    //Определение угла наклона левой стороны скана
    cv::Point point;
    int x1,x2,y1,y2,num_Y=150;
    int x_array[N], y_array[N];

    for (int i=0;i<N;i++)
    {
        get_point_xy(x_array,y_array,num_Y,canny_mat1);
        num_Y+=10;
    }
    jjj=0;


    double a=0,b=0,angel=0;
    mnk(a,b,x_array,y_array,N); //линейная аппроксимация точек на границе банкноты
    //qDebug() << "tg наклона:"<< a;
    angel=atan(a)*180.0/3.14159265; // угол поворота
    if (angel<0) {
        angel=180+angel;
    }
    qDebug() << "угол наклона:"<< angel;


//    }
//    int angel;

    //angel=90;
    //cv::cvtColor( canny_mat, canny_mat_color, cv::IMREAD_COLOR );
    //cv::line(canny_mat_color,cv::Point(x_array[0],y_array[0]),cv::Point(x_array[N-1],y_array[N-1]),cv::Scalar(0,0,255));
    //cv::Vec<cv::Vec4i,100> hierarchy;
    //cv::Vec<cv::Vec<cv::Point,100>,100> contours;
    //cv::findContours(tmp,contours , hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point(0,0));
    int top_offset_y, left_offset_x, bot_offset_y, right_offset_x; //Сдвиг банкноты вверх; //Сдвиг банкноты
    int rows, cols;
    rows =  canny_mat1.rows;
    cols = canny_mat1.cols;

    // Поворачиваем изображение на найденный угол (выравниваем по горизонту)
    cv::Mat rot = cv::getRotationMatrix2D(cv::Point2f(cols/2,rows/2),(angel),1);
    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), canny_mat1.size(),angel).boundingRect2f();
    rot.at<double>(0,2) += bbox.width/2.0 - canny_mat1.cols/2.0;
    rot.at<double>(1,2) += bbox.height/2.0 - canny_mat1.rows/2.0;
    cv::warpAffine(canny_mat1, canny_mat_wrapped, rot, bbox.size()); //bbox.size()

    cv::Mat rot2 = cv::getRotationMatrix2D(cv::Point2f(cols/2,rows/2),(angel),1);
    cv::Rect2f bbox2 = cv::RotatedRect(cv::Point2f(), src_extended.size(),angel).boundingRect2f();
    rot2.at<double>(0,2) += bbox2.width/2.0 - canny_mat1.cols/2.0;
    rot2.at<double>(1,2) += bbox2.height/2.0 - canny_mat1.rows/2.0;
    cv::warpAffine(src_extended, src_wrapped, rot2, bbox2.size()); //bbox.size()


//    static const std::string kWinName = "Canny_wrapped";
//    namedWindow(kWinName,cv::WINDOW_NORMAL);
//    imshow(kWinName, canny_mat_wrapped);

//    static const std::string kWinName9 = "Src_wrapped";
//    namedWindow(kWinName9,cv::WINDOW_NORMAL);
//    imshow(kWinName9, src_wrapped);

    //cv::line(canny_mat_color_wrapped,cv::Point(x_array[0],y_array[0]),cv::Point(x_array[N-1],y_array[N-1]),cv::Scalar(0,255,0));

    //------------------------------------------------------------------------------------------------------------------------------

//    top_offset_y = get_image_top_offcet_y(canny_mat_wrapped);
//    qDebug() <<"top_offset_y"<< top_offset_y;
//    left_offset_x = get_image_left_offcet_x(canny_mat_wrapped);
//    qDebug() <<"left_offset_x"<< left_offset_x;
//    right_offset_x = get_image_right_offcet_x(canny_mat_wrapped);
//    qDebug() <<"right_offset_x"<< right_offset_x;
//    bot_offset_y=get_image_bot_offcet_y(canny_mat_wrapped);
//    qDebug() <<"bot_offset_y"<< bot_offset_y;
//    cv::Rect myROI(cv::Point(left_offset_x, top_offset_y), cv::Point(right_offset_x, bot_offset_y));
    //------------------------------------------------------------------------------------------------------------------------------


    //находим расстояния, на которое надо сдвинуть изображение
    top_offset_y = get_image_top_offcet_y(canny_mat_wrapped);
    qDebug() <<"top_offset_y"<< top_offset_y;
    //Сдвигаем изображение, чтобы получить банкноту в левом верхнем углу
    cv::Mat trans_mat_y = (cv::Mat_<double>(2,3) << 1, 0, 0 /*offsetx */, 0, 1, -top_offset_y /*offsety */);
    cv::Mat canny_mat_wrapped_transed_y, canny_mat_wrapped_transed_xy;
    cv::warpAffine(canny_mat_wrapped,canny_mat_wrapped_transed_y,trans_mat_y,canny_mat_wrapped.size());


//    static const std::string kWinName11 = "1";
//    namedWindow(kWinName11,cv::WINDOW_NORMAL);
//    imshow(kWinName11, canny_mat_wrapped_transed_y);
//    cv::waitKey(-1);

    left_offset_x = get_image_left_offcet_x(canny_mat_wrapped_transed_y);
    qDebug() <<"left_offset_x"<< left_offset_x;
    cv::Mat trans_mat_x = (cv::Mat_<double>(2,3) << 1, 0, -left_offset_x/*offsetx */, 0, 1, 0 /*offsety */);
    cv::warpAffine(canny_mat_wrapped_transed_y,canny_mat_wrapped_transed_xy,trans_mat_x,canny_mat_wrapped_transed_y.size());

//    static const std::string kWinName22= "2";
//    namedWindow(kWinName22,cv::WINDOW_NORMAL);
//    imshow(kWinName22, canny_mat_wrapped_transed_xy);
//    cv::waitKey(-1);

    right_offset_x = get_image_right_offcet_x(canny_mat_wrapped_transed_xy);
    qDebug() <<"right_offset_x"<< right_offset_x;
    bot_offset_y=get_image_bot_offcet_y(canny_mat_wrapped_transed_xy);
    qDebug() <<"bot_offset_y"<< bot_offset_y;

    //Переходим к использованию матрицы кени с нормальными значениями порогов для просмотра серийных номеров
//    cv::Canny(src, canny_mat2, threshold1, threshold2, 3);

    // Поворачиваем изображение на найденный угол (выравниваем по горизонту)
    //cv::warpAffine(src, canny_mat_wrapped, rot, bbox.size()); //bbox.size()

    // Сдвигаем изображение, чтобы получить банкноту в левом верхнем углу
    cv::warpAffine(src_wrapped,canny_mat_wrapped_transed_y,trans_mat_y,src_wrapped.size());

//    static const std::string kWinName33= "3";
//    namedWindow(kWinName33,cv::WINDOW_NORMAL);
//    imshow(kWinName33, canny_mat_wrapped_transed_y);

    cv::warpAffine(canny_mat_wrapped_transed_y,canny_mat_wrapped_transed_xy,trans_mat_x,canny_mat_wrapped_transed_y.size());

//    static const std::string kWinName44= "4";
//    namedWindow(kWinName44,cv::WINDOW_NORMAL);
//    imshow(kWinName44, canny_mat_wrapped_transed_xy);


    //кадрируем банкноту
    cv::Rect myROI(cv::Point(0, 0), cv::Point(right_offset_x, bot_offset_y));
//        cv::Rect myROI(cv::Point(1292,118),cv::Point(1586,187));
    cv::Mat croppedRef(canny_mat_wrapped_transed_xy, myROI);
    cv::Mat cropped,cropped_color,cropped_canny,cropped_canny_color;
    croppedRef.copyTo(cropped);

//    char l[] = "1";
//    l[0]=h;
//    char* Canny_window2 = l;
//    namedWindow( Canny_window2, cv::BORDER_DEFAULT );
//    imshow(Canny_window2, cropped);
//    cv::waitKey(-1);

    cvtColor(cropped, cropped,cv::COLOR_BGR2RGBA); //cv::COLOR_RGB2BGR

    return cropped;






//    src.release();
//    src_gray.release();
//    canny_mat1.release();
//    canny_mat_color_wrapped.release();
//    canny_mat_wrapped.release();
//    trans_mat_y.release();
//    canny_mat_wrapped_transed_y.release();
//    canny_mat_wrapped_transed_xy.release();
//    trans_mat_x.release();
//    croppedRef.release();
//    cropped_color.release();
//    cropped_canny.release();
//    cropped_canny_color.release();


//    cropped.release();
}

void mirror_image(cv::Mat &source_img, cv::Mat &dst)
{
//    char b[] = "Canny_window";
//    char* Canny_window = b;
//    char d[] = "images/image1.bmp";

    //cv::Mat source_img = cv::imread(d,cv::IMREAD_GRAYSCALE);

    cv::Mat flipped_mat;
    cv::flip(source_img,flipped_mat,+1);

//    namedWindow(Canny_window,cv::WINDOW_NORMAL);
//    imshow(Canny_window, flipped_mat);

    dst=flipped_mat;
}




int get_mid_y(cv::Mat &source) // вычисляем Y координату серединной линии разделения скана купюры в белом и инфракрасном
{
    cvtColor(source, source,cv::COLOR_RGB2BGR);
//    char d[] = "images/image1.bmp";
//    cv::Mat source_img = cv::imread(d,cv::IMREAD_COLOR);
//    source=source_img;

    int x=200;
    int count=0;
    int last_y;
    for (int i=0;i<N;i++)
    {
        for (int j=((source.rows/2)+50); j>((source.rows/2)-50); j--)
        {
            //at<uchar>(cv::Point(x,j))
            if ( source.at<cv::Vec3b>(j,i)[0] > 240 )
            //if (source_img.at<uchar>(cv::Point(x,j)) > 100)
            {
                if (last_y=j){
                    count++;
                }
                else{
                    count=0;
                }
                if (count>5)
                {
                    qDebug()<<"срединный Y="<<j;
                    return j;
                }
                last_y=j;
                x+=4;
                break;
            }
        }
    }
    return 0;

}


int divide_images(cv::Mat &source, cv::Mat &white_spect, cv::Mat &infrared_spect)  // делим скан надвое
{
//    char d[] = "images/image00001.bmp";
//    cv::Mat source_img = cv::imread(d,cv::IMREAD_COLOR);
//    source=source_img;

    //mirror_image(source,source);//зеркалим

    cvtColor(source, source,cv::COLOR_RGBA2RGB);
//    int width=source.cols;
//    int hight=source.rows*1.6;
//    cv::resize(source,source,Size(width,hight));

//    char b[] = "white_spect_img";
//    char* white_spect_img = b;
//    namedWindow(white_spect_img,cv::WINDOW_NORMAL);
//    imshow(white_spect_img, source);
//    vector<int> compression_params;
//        compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
//        compression_params.push_back(9);
//        imwrite("alpha.png", source, compression_params);
//    cv::waitKey(-1);

    int mid_y= source.rows/2;   //get_mid_y(source);//находим линию деления
    if (mid_y<0)return 0;

    cv::Rect myROI1(cv::Point(0, 0), cv::Point(source.cols,mid_y));
    cv::Mat cropped1(source, myROI1);
    cv::Rect myROI2(cv::Point(0, mid_y+3),cv::Point(source.cols, source.rows));
    cv::Mat cropped2(source, myROI2);

//    cv::rectangle(cropped1,cv::Point(3,3),cv::Point(cropped1.cols-3,cropped1.rows-3),cv::Scalar(0,0,0),7,8,0);
//    cv::rectangle(cropped2,cv::Point(3,3),cv::Point(cropped2.cols-3,cropped2.rows-3),cv::Scalar(0,0,0),7,8,0);



    infrared_spect=cropped1;
    white_spect=cropped2;
    return 1;

//    char b[] = "white_spect_img";
//    char* white_spect_img = b;
//    namedWindow(white_spect_img,cv::WINDOW_NORMAL);
//    imshow(white_spect_img, cropped1);

//    char c[] = "infra_red_img";
//    char* infra_red_img = c;
//    namedWindow(infra_red_img,cv::WINDOW_NORMAL);
//    imshow(infra_red_img, cropped2);
//    cv::waitKey(-1);
}

void rotate180(cv::Mat &source, cv::Mat &dst,int angel)  // переворачиваем изображение
{
    cv::Mat rot = cv::getRotationMatrix2D(cv::Point2f(source.cols/2,source.rows/2),(angel),1);
    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), source.size(),angel).boundingRect2f();
    rot.at<double>(0,2) += bbox.width/2.0 - source.cols/2.0;
    rot.at<double>(1,2) += bbox.height/2.0 - source.rows/2.0;
    cv::warpAffine(source, dst, rot, bbox.size()); //bbox.size()
}


