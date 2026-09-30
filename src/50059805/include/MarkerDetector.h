#pragma once

#include <opencv2/opencv.hpp>

#include <vector>

struct MarkerResult {
  bool detected_ = false;
  std::vector<cv::Point2f> points_;
  cv::Rect bounding_box_;
};

class MarkerDetector {
 public:
  MarkerDetector();
  MarkerResult detect(const cv::Mat& frame);

 private:
  cv::Mat preprocess(const cv::Mat& frame);
  std::vector<cv::Point2f> sortPoints(const std::vector<cv::Point2f>& pts);
};