#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

class PoseEstimator {
 public:
  PoseEstimator(const cv::Mat& camera_matrix, const cv::Mat& dist_coeffs);

  // 位姿解算
  bool solve(const std::vector<cv::Point2f>& image_points,
             const std::vector<cv::Point3f>& object_points);

  // 绘制坐标轴
  void drawAxis(cv::Mat& frame, float axis_length);

  // 获取平移向量和旋转向量
  cv::Vec3d getTvec() const { return tvec_; }
  cv::Vec3d getRvec() const { return rvec_; }

 private:
  cv::Mat camera_matrix_;
  cv::Mat dist_coeffs_;
  cv::Vec3d rvec_, tvec_;
};