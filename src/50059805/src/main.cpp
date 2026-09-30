#include <iostream>
// #include "MarkerDetector.h"
#include <string>
#include <opencv2/opencv.hpp>

int main() {
  std::string path = "../test_pic/pic1.png";
  cv::Mat frame;
  frame = cv::imread(path);
  cv::Mat gray;

  cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
  cv::inRange(gray, cv::Scalar(200), cv::Scalar(255), gray);
  cv::imshow("gray", gray);
  return 0;
}