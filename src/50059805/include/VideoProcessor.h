#pragma once

#include "MarkerDetector.h"
#include <string>


class VideoProcessor {
 public:
  VideoProcessor();
  void run(const std::string& videoPath);
 private:
  MarkerDetector detector_;
  int lostFrames_ = 0;
  int detectedFrames_ = 0;
  const int MAX_LOST_FRAMES = 5;
  const int MIN_DETECTED_FRAMES = 3;
  MarkerResult lastResult_;

  void updateState(const MarkerResult& currentResult);
};