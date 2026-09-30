#include "VideoProcessor.h"

VideoProcessor::VideoProcessor() {}

void VideoProcessor::run(const std::string& videoPath) {
  cv::VideoCapture cap(videoPath);
  if (!cap.isOpened()) {
    return;
  }
  cv::Mat frame;

  
}