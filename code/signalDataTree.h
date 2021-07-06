#ifndef SIGNALDATATREE
#define SIGNALDATATREE

#include "TFile.h"
#include "TTree.h"

class signalDataTree
{
public:
  signalDataTree(std::string outputName);
  ~signalDataTree();
  bool setCharge(double value, int channel);
  bool setAmplitude(double value, int channel);
  bool setRiseTime(double value, int channel);
  bool setFallTime(double value, int channel);
  bool setTimeAtThr(double value, int channel);
  bool setBaseline(double value, int channel);
  bool setFileNumber(int number);
  bool fill();
private:
  TFile* f2;
  double fCharge1 = 0, fCharge2 = 0, fCharge3 = 0;
  double fRiseTime1 = 0, fRiseTime2 = 0, fRiseTime3 = 0;
  double fFallTime1 = 0, fFallTime2 = 0, fFallTime3 = 0;
  double fAmplitude1 = 0, fAmplitude2 = 0, fAmplitude3 =0;
  double fBaseline1 = 0, fBaseline2 = 0, fBaseline3 = 0;
  double ERRORflag1 = 0, ERRORflag2 = 0, ERRORflag3 = 0;
  double fTimeAtThr1 = 0, fTimeAtThr2 = 0, fTimeAtThr3 = 0;
  int fFileNumber = 0;
  TTree *fTree;
};

#endif
