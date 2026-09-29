#pragma once

#include <opencv2/opencv.hpp>

#include <vector>

struct MarkerResult {
  bool detected = false;
  std::vector<cv::Point2f> vertices;
  cv::Rect boundingBox;
};

class MarkerDetector {
 public:
  MarkerDetector();
  MarkerResult detect(const cv::Mat& frame);

 private:
  cv::Mat preprocess(const cv::Mat& frame);
  std::vector<cv::Point2f> sortVertices(const std::vector<cv::Point2f>& pts);
};