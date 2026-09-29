#pragma once

#include "MarkerDetector.h"
#include <string>


class VideoProcessor {
 public:
  VideoProcessor();
  void run(const std::string& videoPath);
 private:
  MarkerDetector m_detector;
  int m_lostFrames = 0;
  int m_detectedFrames = 0;
  const int MAX_LOST_FRAMES = 5;
  const int MIN_DETECTED_FRAMES = 3;
  MarkerResult m_lastResult;

  void updateState(const MarkerResult& currentResult);
};