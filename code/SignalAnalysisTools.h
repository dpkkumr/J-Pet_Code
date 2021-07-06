
#ifndef SIGNALANALYSISTOOLS
#define SIGNALANALYSISTOOLS

#include <iostream>


class signalAnalysisTools{


public:


static double calculateTimeAtThreshold(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold);
static double calculateConstantThresholdFall(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold);
static double calculateConstantThreshold(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold);
static double timeFall(std::pair<std::vector<double>, std::vector<double> >& data, double offset, double amplitude);
static double timeRise(std::pair<std::vector<double>, std::vector<double> >& data, double baseline, double amplitude);
static double pktPrzecieciaOX(double x1, double y1, double x2, double y2);
static int findStartingIndex(std::vector<double>& amplitudePoints);
static int findEndingIndex(std::vector<double>& amplitudePoints, double baseline);
static double calculateAreaFromStartingIndex(std::pair<std::vector<double>, std::vector<double> >& data, double offset);
static double calculateBaseline(std::vector<double>& amplitudePoints);
static int findIndexAtValue(double value, std::vector<double>& vector);
static double calculateArithmeticMean(const std::vector<double>& vector, const int upToIndex);
static double calculateStandardDeviation(const std::vector<double>& vector, const int upToIndex);
static bool isPointFromRecoSignalInNoise(const double noiseMean, const double noiseDeviation, const double point);
static double min(const std::vector<double>& vector);
static double absolute(const double number);
};
#endif
