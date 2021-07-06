{
  TString path = gSystem->pwd();

  gROOT->ProcessLine(".L " + path + "/signalDataTree.cpp+");
  gROOT->ProcessLine(".L " + path + "/SignalAnalysisTools.cpp+");
  gROOT->ProcessLine(".L " + path + "/SignalExtraction.cpp+");
  gROOT->ProcessLine(".L " + path + "/findComptonEdge.cpp+");
  gROOT->ProcessLine(".L " + path + "/producePlots.cpp");
}
