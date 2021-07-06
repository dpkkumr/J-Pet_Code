#ifndef SIGNALEXTRACTION
#define SIGNALEXTRACTION

#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <stdio.h>
#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <utility>

#include "TGraph.h"
#include "TCanvas.h"
#include "TROOT.h" 
#include "TBranch.h"
#include "TMath.h"
#include "TTree.h"
#include "TFile.h"
#include "TGraph.h"
#include "Riostream.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TStyle.h"
#include "TPad.h"
#include "TH1.h"
#include "TLine.h"
#include "TH2.h"
#include "TLegend.h"
#include "TAttMarker.h"
#include "TPaletteAxis.h"
#include "TColor.h"

std::string exec(std::string cmd);
std::string convertIntToString(const int integer);
bool checkIfFileExists(const std::string path);
std::string makeFilePath(const std::string initialPath, const int channelNb, const int eventNb);
void readDataFile( std::ifstream& file, std::pair<std::vector<double>, std::vector<double> >& data);
std::string makeSignalPath(const std::string initialPath, const int channelNb, const int eventNb);
std::string setTitleofGraphs( const int channelNb, const int eventNb);
void generateGraphs( std::pair<std::vector<double>, std::vector<double> >& data , const int channelNb, const int eventNb, const std::string path);
std::string setTitleofGraphs( const int channelNb, const int eventNb);

#endif
