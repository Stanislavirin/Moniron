#include "text_detection.h"
#include <QDebug>
using namespace cv;
using namespace cv::dnn;


//в src - исходная матрица
//если текст обнаружился - возвращаем 1, иначе 0
// right_region - правая верхняя часть скана купюры
// left_bottom - левая нижняя часть скана купюры
// left_vertical - левая вертикальная часть скана купюры
// result - массив результатов обнаружения: если обнаружился текст в right_region - result[1] =1; иначе 0 и тд
//
int getAllRegionsWithText(cv::dnn::Net& net,cv::Mat& src, cv::Mat& right_serial, cv::Mat& left_serial,int* result)
{
    result[0]=0;
    result[1]=0;
    result[2]=0;
    result[3]=0;
    int x1[4]={src.cols-20-584 ,22,88,47}, y1[4]={99,476,90,331}, x2[4]={src.cols-20 ,435,189,524}, y2[4]={195,595,630,427}; // 1029   1509
    //int x1[4]={src.cols-20-480,21,49,113}, y1[4]={99,476,341,96}, x2[4]={src.cols-20,356,332,190}, y2[4]={180,550,415,539}; //1039   1500
//    if ( cols > 1586 ) // если купюра большая (5000/2000/1000), в плане размера
//    {
//         x1[0]=1106; x1[1]=26;  x1[2]=103;
//         y1[0]=109;  y1[1]=517; y1[2]=157;
//         x2[0]=1586; x2[1]=378; x2[2]=199;
//         y2[0]=205;  y2[1]=581; y2[2]=605;
//    }
//        if ( cols > 1575 ) // если купюра большая (5000/2000/1000), в плане размера
//        {
//             x1[0]=cols-15-480; x1[1]=26;  x1[2]=103; // 1106
//             y1[0]=109;         y1[1]=505; y1[2]=157;
//             x2[0]=cols-15;     x2[1]=378; x2[2]=199; // 1586
//             y2[0]=205;         y2[1]=590; y2[2]=605;
//        }

    //float confThreshold = 0.5;
    //float nmsThreshold = 0.4;
    //int inpWidth[3]={x2[0]-x1[0], x2[1]-x1[1], x2[2]-x1[2]};//= x2-x1;  //640
    //int inpHeight[3]={y2[0]-y1[0] , y2[1]-y1[1] , y2[2]-y1[2]};//= y2-y1; //128

    //Проверка правого верхнего серийника
    cv::Mat cropped_result0,cropped_result1,cropped_result2,cropped_result3;
    cv::Mat rec608x128_0;
    cv::Size sz0(608,128); //608
    rec608x128_0.create(sz0,CV_8UC3);
    cv::Rect myROI0(cv::Point(x1[0],y1[0]),cv::Point(x2[0],y2[0]));
    cv::Mat croppedRef0(src, myROI0);
    //croppedRef.copyTo(rec480x96);
    copyToImage(croppedRef0, rec608x128_0);

    //rec480x96=src(Rect(x1[0], y1[0], 400, 96));

    if (isThereTextInRegion(net,rec608x128_0,cropped_result0)) {
        qDebug()<<"right region";
        result[0]=1;
        right_serial=croppedRef0;
        static const std::string kWinName0 = "right region";
        namedWindow(kWinName0, WINDOW_NORMAL);
        imshow(kWinName0, cropped_result0);
    }


    //Проверка левого вертикального серийника
    cv::Mat rec608x128_2;
    cv::Size sz2(608,128);
    rec608x128_2.create(sz2,CV_8UC3);
    cv::Rect myROI2(cv::Point(x1[2],y1[2]),cv::Point(x2[2],y2[2]));
    cv::Mat croppedRef2(src, myROI2);

    cv::Mat croppedRef2_wrapped;
    // Поворачиваем изображение на 90+180 градусов
    cv::Mat rot = cv::getRotationMatrix2D(cv::Point2f(croppedRef2.cols/2,croppedRef2.rows/2),(90+180),1);
    cv::Rect2f bbox = cv::RotatedRect(cv::Point2f(), croppedRef2.size(),90+180).boundingRect2f();
    rot.at<double>(0,2) += bbox.width/2.0 - croppedRef2.cols/2.0;
    rot.at<double>(1,2) += bbox.height/2.0 - croppedRef2.rows/2.0;
    cv::warpAffine(croppedRef2, croppedRef2_wrapped, rot, bbox.size()); //bbox.size()


    copyToImage(croppedRef2_wrapped, rec608x128_2);
    if (isThereTextInRegion(net,rec608x128_2,cropped_result2)) {
        qDebug()<<"left region 200/2000";
        result[2]=1;
        left_serial=croppedRef2_wrapped;
        static const std::string kWinName2 = "left region 200/2000";
        namedWindow(kWinName2, WINDOW_NORMAL);
        imshow(kWinName2, cropped_result2);
    }
    //if ( cols < 1575 )
    {
        //Проверка левого серийника 50/100
        cv::Mat rec608x128_3;
        cv::Size sz3(608,128);
        rec608x128_3.create(sz3,CV_8UC3);
        cv::Rect myROI3(cv::Point(x1[3],y1[3]),cv::Point(x2[3],y2[3]));
        cv::Mat croppedRef3(src, myROI3);
        copyToImage(croppedRef3, rec608x128_3);
        if (isThereTextInRegion(net,rec608x128_3,cropped_result3)) {
            qDebug()<<"left bottom region for 50/100";
            result[3]=1;
            left_serial=croppedRef3;
            static const std::string kWinName3 = "left bottom region for 50/100";
            namedWindow(kWinName3, WINDOW_NORMAL);
            imshow(kWinName3, cropped_result3);
        }
    }


    //Проверка левого серийника
    cv::Mat rec608x128_1;
    cv::Size sz1(608,128);
    rec608x128_1.create(sz1,CV_8UC3);
    cv::Rect myROI1(cv::Point(x1[1],y1[1]),cv::Point(x2[1],y2[1]));
    cv::Mat croppedRef1(src, myROI1);
    copyToImage(croppedRef1, rec608x128_1);
    if (isThereTextInRegion(net,rec608x128_1,cropped_result1)) {
        qDebug()<<"left bottom region 500/1000/5000";
        result[1]=1;
        left_serial=croppedRef1;
        static const std::string kWinName1 = "left bottom region 500/1000/5000";
        namedWindow(kWinName1, WINDOW_NORMAL);
        imshow(kWinName1, cropped_result1);
    }



    qDebug() << result[0]<< result[1]<< result[2]<< result[3] ;
    if ( (result[0] | result[1] | result[2] | result[3] ))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void decode(const Mat& scores, const Mat& geometry, float scoreThresh,
            std::vector<RotatedRect>& detections, std::vector<float>& confidences)
{
    detections.clear();
    CV_Assert(scores.dims == 4); CV_Assert(geometry.dims == 4); CV_Assert(scores.size[0] == 1);
    CV_Assert(geometry.size[0] == 1); CV_Assert(scores.size[1] == 1); CV_Assert(geometry.size[1] == 5);
    CV_Assert(scores.size[2] == geometry.size[2]); CV_Assert(scores.size[3] == geometry.size[3]);

    const int height = scores.size[2];
    const int width = scores.size[3];
    for (int y = 0; y < height; ++y)
    {
        const float* scoresData = scores.ptr<float>(0, 0, y);
        const float* x0_data = geometry.ptr<float>(0, 0, y);
        const float* x1_data = geometry.ptr<float>(0, 1, y);
        const float* x2_data = geometry.ptr<float>(0, 2, y);
        const float* x3_data = geometry.ptr<float>(0, 3, y);
        const float* anglesData = geometry.ptr<float>(0, 4, y);
        for (int x = 0; x < width; ++x)
        {
            float score = scoresData[x];
            if (score < scoreThresh)
                continue;

            // Decode a prediction.
            // Multiple by 4 because feature maps are 4 time less than input image.
            float offsetX = x * 4.0f, offsetY = y * 4.0f;
            float angle = anglesData[x];
            float cosA = std::cos(angle);
            float sinA = std::sin(angle);
            float h = x0_data[x] + x2_data[x];
            float w = x1_data[x] + x3_data[x];

            Point2f offset(offsetX + cosA * x1_data[x] + sinA * x2_data[x],
                           offsetY - sinA * x1_data[x] + cosA * x2_data[x]);
            Point2f p1 = Point2f(-sinA * h, -cosA * h) + offset;
            Point2f p3 = Point2f(-cosA * w, sinA * w) + offset;
            RotatedRect r(0.5f * (p1 + p3), Size2f(w, h), -angle * 180.0f / (float)CV_PI);
            detections.push_back(r);
            confidences.push_back(score);
        }
    }
}



// определяем, есть ли в области src серийный номер
// если номер есть - возвращаем 1, иначе 0
int isThereTextInRegion(cv::dnn::Net& net,cv::Mat& src, cv::Mat& dst)
{
    const int x1=0,y1=0,x2=src.cols,y2=src.rows;
    const char* keys =
            "{ help  h     | | Print help message. }"
            "{ input i     | | Path to input image or video file. Skip this argument to capture frames from a camera.}"
            "{ model m     | frozen_east_text_detection.pb | Path to a binary .pb file contains trained network.}"
            "{ width       | 320 | Preprocess input image by resizing to a specific width. It should be multiple by 32. }"
            "{ height      | 320 | Preprocess input image by resizing to a specific height. It should be multiple by 32. }"
            "{ thr         | 0.5 | Confidence threshold. }"
            "{ nms         | 0.4 | Non-maximum suppression threshold. }";

    float confThreshold = 0.5;
    float nmsThreshold = 0.4;
    int inpWidth=608;  //480
    int inpHeight=128; //96

    int result=0;

    std::vector<Mat> output;
    std::vector<String> outputLayers(2);
    outputLayers[0] = "feature_fusion/Conv_7/Sigmoid";
    outputLayers[1] = "feature_fusion/concat_3";
    Mat blob,cropped;



    // if ( getRegionWithText(src, right_region, net,1024, 96, 1536, 192) ) result[0]=1; //1024, 96, 1536, 192
    //static const std::string kWinName = "EAST: An Efficient and Accurate Scene Text Detector";
    //namedWindow(kWinName, WINDOW_NORMAL);

    //        //Подргужаем нейросеть для детектирования текста
    //        cv::String model = "C:\\Users\\stani\\Documents\\text_detection_project\\frozen_east_text_detection.pb";
    //        CV_Assert(!model.empty());
    //        // Load network.
    //        cv::dnn::Net net2 = cv::dnn::readNet(model);

    //        cv::Rect myROI(cv::Point(x1,y1),cv::Point(x2,y2));
    //        cv::Mat croppedRef(src, myROI);
    //        croppedRef.copyTo(cropped);
    //        frame=cropped;

    blobFromImage(src, blob, 1.0, Size(inpWidth, inpHeight), Scalar(123.68, 116.78, 103.94), true, false);
    net.setInput(blob);
    net.forward(output, outputLayers);

    Mat scores = output[0];
    Mat geometry = output[1];

    // Decode predicted bounding boxes.
    std::vector<RotatedRect> boxes;
    std::vector<float> confidences;
    decode(scores, geometry, confThreshold, boxes, confidences);

    // Apply non-maximum suppression procedure.
    std::vector<int> indices;
    NMSBoxes(boxes, confidences, confThreshold, nmsThreshold, indices);


//    static const std::string kWinName = "indices";
//    namedWindow(kWinName, WINDOW_NORMAL);
    int a=1,b=1;
    int color=255;
    // Render detections.
    qDebug()  << "indices.size()="<< indices.size();
    Point2f ratio((float)src.cols / inpWidth, (float)src.rows / inpHeight);
    for (size_t i = 0; i < indices.size(); ++i)
    {
        RotatedRect& box = boxes[indices[i]];
        Point2f vertices[4];
        box.points(vertices);
        for (int j = 0; j < 4; ++j)
        {
            vertices[j].x *= ratio.x;
            vertices[j].y *= ratio.y;
        }
//        for (int j = 0; j < 4; ++j) line(src, vertices[j], vertices[(j + 1) % 4], Scalar(0, 255, 0), 2, LINE_AA);
        if (  ((vertices[0].x>0) & (vertices[0].x<x2) & (vertices[0].y>0) & (vertices[0].y<y2))
           &  ((vertices[1].x>0) & (vertices[1].x<x2) & (vertices[1].y>0) & (vertices[1].y<y2))
           &  ((vertices[2].x>0) & (vertices[2].x<x2) & (vertices[2].y>0) & (vertices[2].y<y2))
           &  ((vertices[3].x>0) & (vertices[3].x<x2) & (vertices[3].y>0) & (vertices[3].y<y2))  )
        {
            if ( ((vertices[0].y-vertices[1].y) > 28) & ((vertices[0].y-vertices[1].y) < 60) & ((vertices[2].x - vertices[0].x) > 100) )  //проверяем, большой ли текст, но не слишком по высоте обнаружился
            {
                //if ( ((vertices[0].x-vertices[1].x) > 60) | ((vertices[1].x-vertices[2].x) > 60) ) //проверяем, большой ли текст по ширине обнаружился

                qDebug()<<"current I="<<i;
                if(i>1)
                {
                    for (size_t i2 = i; i2 > 0; --i2)
                    {
                        RotatedRect& box2 = boxes[indices[i2]];
                        Point2f vertices2[4];
                        box2.points(vertices2);
                        for (int j2 = 0; j2 < 4; ++j2)
                        {
                            vertices2[j2].x *= ratio.x;
                            vertices2[j2].y *= ratio.y;
                        }

                        for (int j = 0; j < 4; ++j) line(src, vertices2[j], vertices2[(j + 1) % 4], Scalar(color, 0, 0), 2, LINE_AA);
                        color-=125;
                        if ( (vertices2[3].x>vertices[3].x) & ((vertices2[0].x>vertices[0].x) & (vertices2[0].x<vertices[3].x+20))   )
                        {
                            vertices[2].x=vertices2[2].x;
                            vertices[3].x=vertices2[3].x;
                            if (vertices2[3].y<vertices[3].y)
                            {
                                vertices[3].y=vertices2[3].y;
                            }
                        }
                        qDebug()<<"right box №"<<a;
                        a++;
                    }
                }
                if (indices.size()-i>1)
                {
                    for (size_t i2 = i+1; i2 < indices.size(); ++i2)
                    {
                        RotatedRect& box2 = boxes[indices[i2]];
                        Point2f vertices2[4];
                        box2.points(vertices2);
                        for (int j2 = 0; j2 < 4; ++j2)
                        {
                            vertices2[j2].x *= ratio.x;
                            vertices2[j2].y *= ratio.y;
                        }
                        //если еще одна обнаруженная область лежит рядом справа -добавляем ее
                        for (int j = 0; j < 4; ++j) line(src, vertices2[j], vertices2[(j + 1) % 4], Scalar(0, 255, 0), 2, LINE_AA);
                        if ( (vertices2[0].x<vertices[0].x) & (vertices2[3].x<(vertices[3].x) & (vertices2[3].x>vertices[0].x-40) )   )
                        {
                            vertices[0].x=vertices2[0].x;
                            vertices[1].x=vertices2[1].x;
                            if (vertices2[0].y>vertices[0].y)
                            {
                                vertices[0].y=vertices2[0].y;
                            }
                        }
                        qDebug()<<"left box №"<<b;
                        b++;

                    }
                }

                if (vertices[0].y>vertices[3].y)
                {
                    vertices[0].y=vertices[3].y;
                } else
                {
                    vertices[3].y=vertices[0].y;
                }

                if (vertices[1].y>vertices[2].y)
                {
                    vertices[1].y=vertices[2].y;
                } else
                {
                    vertices[2].y=vertices[1].y;
                }

                if ((vertices[0].x-100)<0) vertices[0].x=0; else  vertices[0].x-=100;
                if ((vertices[0].y+5)>src.rows) vertices[0].y=src.rows; else vertices[0].y+=5;
                if ((vertices[1].x-100)<0) vertices[1].x=0; else vertices[1].x-=100;
                if ((vertices[1].y-15)<0) vertices[1].y=0; else vertices[1].y-=15;
                if ((vertices[2].x+15)>src.cols) vertices[2].x+=src.cols; else vertices[2].x+=15;
                if ((vertices[2].y-15)<0) vertices[2].y=0; else vertices[2].y-=15;
                if ((vertices[3].x+15)>src.cols) vertices[3].x=src.cols; else vertices[3].x+=15;
                if ((vertices[3].y+5)>src.rows) vertices[3].y=src.rows; else  vertices[3].y+=5;



                cv::Rect myROI0(cv::Point(vertices[1].x,vertices[1].y),cv::Point(vertices[3].x,vertices[3].y));
                cv::Mat croppedRef0(src, myROI0);
                dst=croppedRef0;
//                dst=src;

                for (int j = 0; j < 4; ++j) line(src, vertices[j], vertices[(j + 1) % 4], Scalar(0, 0, 255), 2, LINE_AA);

                return 1;
                result=1;

            }

        }
    }
return 0;
}


//копируем матрицу из srcFrom в dstTo
void copyToImage(cv::Mat &srcFrom, cv::Mat &dstTo)
{

for (int i = 0; i < srcFrom.rows; i++)
{
    for (int j = 0; j < srcFrom.cols; j++)
    {
        dstTo.at<Vec3b>(i, j) = srcFrom.at<Vec3b>(i, j);
    }
}

}

