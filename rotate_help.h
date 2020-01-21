#ifndef ROTATE_HELP_H
#define ROTATE_HELP_H

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
double sum(int* array,int n);
void mnk(double& a,double& b, int* x_array, int* y_array, int n);
void get_point_xy(int* x_array, int* y_array, int y_num, cv::Mat canny_mat);
double get_arithmetic_mean(int x1, int y1, int x2, int y2, cv::Mat canny_mat);
int get_image_left_offcet_x(cv::Mat canny_mat);
int get_image_top_offcet_y(cv::Mat canny_mat);
int get_image_right_offcet_x(cv::Mat canny_mat);
int get_image_bot_offcet_y(cv::Mat canny_mat);
int getRegionWithText(cv::Mat& src);
cv::Mat turnTheMatAndCashCrop(cv::Mat &src);
void CropBillFromScan(cv::Mat &src, cv::Mat &dest);

void decode(const cv::Mat& scores, const cv::Mat& geometry, float scoreThresh,
            std::vector<cv::RotatedRect>& detections, std::vector<float>& confidences);

void mirror_image(cv::Mat &source_img,cv::Mat &dst); // функция отражения изображения по вертикали
int divide_images(cv::Mat &source, cv::Mat &white_spect, cv::Mat &infrared_spect); //разбиваем инафра и белый спектр
int get_mid_y(cv::Mat &source); // вычисляем Y координату серединной линии разделения скана купюры в белом и инфракрасном
void rotate180(cv::Mat &source, cv::Mat &dst,int angel);  // переворачиваем изображение

#endif // ROTATE_HELP_H
