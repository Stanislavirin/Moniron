#ifndef TEXT_DETECTION_H
#define TEXT_DETECTION_H


#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"



int getAllRegionsWithText(cv::dnn::Net& net,cv::Mat& src, cv::Mat& right_serial, cv::Mat& left_serial,int* result);
int isThereTextInRegion(cv::dnn::Net& net,cv::Mat& src,cv::Mat& dst);

void decode(const cv::Mat& scores, const cv::Mat& geometry, float scoreThresh,
            std::vector<cv::RotatedRect>& detections, std::vector<float>& confidences);
void copyToImage(cv::Mat &srcFrom, cv::Mat &dstTo);

#endif // TEXT_DETECTION_H
