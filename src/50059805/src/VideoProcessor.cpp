#include "VideoProcessor.h"
#include "Visualizer.h"

VideoProcessor::VideoProcessor() {}

void VideoProcessor::run(const std::string& videoPath) {
  cv::VideoCapture cap(videoPath);
  if (!cap.isOpened()) {
    return;
  }
  cv::Mat frame;

  Visualizer visualizer;

  while (cap.read(frame)) {
    if (frame.empty()) {
      break;
    }

    MarkerResult currentResult = detector_.detect(frame);
    updateState(currentResult);

    if (detectedFrames_ >= MIN_DETECTED_FRAMES && lostFrames_ == 0) {
      visualizer.drawMarker(frame, lastResult_);
    } else {
      MarkerResult emptyResult;
      emptyResult.detected = false;
      visualizer.drawMarker(frame, emptyResult);
    }
    cv::imshow("Marker Detection", frame);
    if (cv::waitKey(30) == 27) {  // 按下 'Esc' 键退出
      break;
    }
  }
  cap.release();
  cv::destroyAllWindows();
}


void VideoProcessor::updateState(const MarkerResult& currentResult) {
  if (currentResult.detected) {
    detectedFrames_++;
    lostFrames_ = 0;
    if (detectedFrames_ >= MIN_DETECTED_FRAMES) {
      lastResult_ = currentResult;
    }
  } else {
    lostFrames_++;
    detectedFrames_ = 0;
    if (lostFrames_ > MAX_LOST_FRAMES) {
      lastResult_.detected = false;  // 标记为未检测到
    }
  }
}