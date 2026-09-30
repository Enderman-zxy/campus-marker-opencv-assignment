#pragma once

#include <opencv2/opencv.hpp>

#include <vector>

struct MarkerResult {
  bool detected = false;
  std::vector<cv::Point2f> points;
  cv::Rect boundingBox;

  // 补充，检测是否目标完整处于画面中
  bool is_partical = false;
};

class MarkerDetector {
 public:
  MarkerDetector();
  MarkerResult detect(const cv::Mat& frame);

 private:
  cv::Mat preprocess(const cv::Mat& frame);
  std::vector<cv::Point2f> sortPoints(const std::vector<cv::Point2f>& pts);
};