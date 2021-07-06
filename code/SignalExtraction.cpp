#include "signalDataTree.h"
#include "SignalAnalysisTools.h"
#include "SignalExtraction.h"

const int chNb = 2;   // there are 3 channels on the scope

// /home/szymon/data/srodek/
// /home/szymon/data/srodek.root

int SignalExtraction( std::string path, int signalsToProcess = 0, bool toPlot = false )
{
    std::string directoryPath = path;

    std::string terminalCode = "ls -l ";
    terminalCode+= directoryPath;
    terminalCode+="/*ch";
    terminalCode+=convertIntToString(chNb);
    terminalCode+= "* | wc -l";
    int totalSignals = -1;
    if( signalsToProcess == 0 )
		totalSignals =  atoi( exec( terminalCode).c_str() );
	else
		totalSignals = signalsToProcess;
	
    std::string name = path;
    if( name.back() == '/')
		name.pop_back();
    name += ".root";
    
    std::cout << "Saving to file: " << name << std::endl;
  signalDataTree tree( name ); 


    int counter = 0;
    
 for( int signalNb = 0; signalNb < totalSignals; signalNb++)
     {
       if(signalNb%100 == 0)
          std::cout << signalNb << std::endl;
          
  for( int channelNb = 1; channelNb < chNb+1; channelNb++)
	    { 
        
         if( !checkIfFileExists( makeFilePath(directoryPath, channelNb, signalNb) ) )
	      {
 	       std::cout<<"File does not exist for SignalNb:"<< signalNb<<" ChannelNb: "<<channelNb<<std::endl;
 	       continue;
	      }

	 std::pair<std::vector<double>, std::vector<double>> data;
	 std::ifstream dataFile( makeFilePath(directoryPath, channelNb, signalNb).c_str() );

	 readDataFile( dataFile, data );
     
    dataFile.close();
     
    double baseline = signalAnalysisTools::calculateBaseline(data.second);
    for(unsigned int index = 0; index < data.second.size(); index++)
    {
        data.second[index] = data.second[index] - baseline;
    }
    std::vector<double>& Yaxis = data.second;
    double amplitude = TMath::MinElement(data.second.size(), &Yaxis[0]);
    double charge = signalAnalysisTools::calculateAreaFromStartingIndex(data, 0);
    double time = signalAnalysisTools::calculateTimeAtThreshold(data, 0.25*amplitude);
    double riseTime = signalAnalysisTools::timeRise(data, baseline, amplitude);
    double fallTime = signalAnalysisTools::timeFall(data, baseline, amplitude);
	
	 if(counter < 1000 && toPlot )
	{
		 generateGraphs( data, channelNb, signalNb, directoryPath);
		 counter++;
	 }



    if( !tree.setBaseline( baseline, channelNb ) )
       continue;
    if( !tree.setAmplitude( amplitude, channelNb ) )
		continue; 
    if( !tree.setCharge( charge, channelNb ) )
		continue;
    if( !tree.setTimeAtThr( time, channelNb ) )
		continue;
    if( !tree.setRiseTime( riseTime, channelNb ) )
		continue;
    if( !tree.setFallTime( fallTime, channelNb ) )
		continue;
		
	    }
    tree.setFileNumber( signalNb );
	tree.fill();
     }
    
 return 0;
}
  


std::string convertIntToString(const int integer)
{
  std::string convertedInt = std::to_string(integer);   // to convert int to string
  
  return convertedInt;
}	

  
std::string makeFilePath(const std::string initialPath, const int channelNb, const int eventNb)
{ 
  std::string pathToFile = initialPath;

  if( pathToFile.back() != '/' )
	pathToFile+= "/";
  



  if( eventNb < 10000 )
      pathToFile+="0";
  if( eventNb < 1000 )
      pathToFile+="0";
  if( eventNb < 100 )
      pathToFile+="0";
  if( eventNb < 10 ) 
      pathToFile+="0";

  pathToFile += convertIntToString(eventNb);
  
  pathToFile+= "_ch"; 

  if( channelNb > 0 && channelNb < 4 )
    pathToFile+= convertIntToString(channelNb);
  else
    return "";

  pathToFile += ".tsv";
  return pathToFile;
}

void readDataFile( std::ifstream& file, std::pair<std::vector<double>, std::vector<double> >&  data )
{
  std::string test="";
  for( int headerLines = 0; headerLines < 0; headerLines++ )
  std::getline(file,test);
  
  while( !file.eof() )
  {
     double amplitude, time;
     file >> time >> amplitude;
     data.first.push_back(time*1E9);
     data.second.push_back(amplitude*1E3);
  
  }
}


void generateGraphs( std::pair<std::vector<double>, std::vector<double> >&  data , const int channelNb, const int eventNb, const std::string path)
{
  TCanvas* c = new TCanvas();
  if( data.first.size() == 0 )
	  return;
  TGraph* signal = new TGraph( data.first.size(), &data.first[0], &data.second[0] );
  //TGraph* signal = new TGraph( data.first.size(), &data.first[0], &data.second[0] );
  
  signal->GetXaxis()->SetTitle("Time [ns]"); 
  signal->GetXaxis()->CenterTitle();
  signal->GetYaxis()->SetTitle("Amplitude [mV]"); 
  signal->GetYaxis()->CenterTitle(); 

  std::string graphTitle = setTitleofGraphs( channelNb, eventNb);
  signal->SetTitle( graphTitle.c_str() ); 
  double base = signalAnalysisTools::calculateBaseline(data.second);

  TLine* baseline = new TLine(data.first[0], base, data.first[ data.first.size() -1], base );
  baseline->SetLineColor(2);
  baseline->SetLineWidth(8);

    std::vector<double>& Yaxis = data.second;
    double amplitude = TMath::MinElement(data.second.size(), &Yaxis[0]);
  TLine* amplitudeLine = new TLine(data.first[0], amplitude, data.first[ data.second.size() -1], amplitude);
  amplitudeLine->SetLineColor(5);
  amplitudeLine->SetLineWidth(8);

  double timeAtThr = signalAnalysisTools::calculateTimeAtThreshold(data, -50);
  TLine* threshold = new TLine(data.first[0], -50, timeAtThr, -50);
  threshold->SetLineColor(3);
  threshold->SetLineWidth(8);

  double timeAt10 = signalAnalysisTools::calculateTimeAtThreshold(data, amplitude*0.2);
  TLine* lineAt10 = new TLine( data.first[0], amplitude*0.2, timeAt10, amplitude*0.2 ); 
  lineAt10->SetLineColor(4);
  lineAt10->SetLineWidth(3);
  
  gPad->SetTicks(1,1);
  gStyle->SetOptStat(0);
  
  signal->Draw("AP");
  baseline->Draw();
  amplitudeLine->Draw();
  threshold->Draw();
  lineAt10->Draw();
  signal->SetMarkerStyle(23);

  std::string signalName = makeSignalPath(path, channelNb, eventNb);
  c->SaveAs(signalName.c_str());    // conversion of string to const char*
}

 std::string makeSignalPath(const std::string initialPath, const int channelNb, const int eventNb)
{ 
  std::string pathToFile = initialPath;


  if( pathToFile.back() != '/' )
	pathToFile+= "/";

  pathToFile+="toPNG/";
  pathToFile+= "C"; 

  if( channelNb > 0 && channelNb < 5 )
    pathToFile+= convertIntToString(channelNb);
  else
    return "";

  pathToFile += "_";

  if( eventNb < 10000 )
      pathToFile+="0";
  if( eventNb < 1000 )
      pathToFile+="0";
  if( eventNb < 100 )
      pathToFile+="0";
  if( eventNb < 10 ) 
      pathToFile+="0";
  
  pathToFile += convertIntToString(eventNb);
  pathToFile += ".png";//".root";
  return pathToFile;
}      

 bool checkIfFileExists(const std::string path)
{
  std::fstream fileCheck( path.c_str() );
  if (fileCheck)
  {
    //std::cout<<"File exists: " << path <<std::endl;
    return true;
  }
  std::cout<<"File does not exists: " << path <<std::endl;
  fileCheck.close();
  return false;
}

std::string exec(std::string cmd) {              
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");                 
    if (!pipe) throw std::runtime_error("popen() failed!");          
    try {                                          
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

std::string setTitleofGraphs( const int channelNb, const int eventNb)
{ 
  std::string pathToFile = "C";
  
  if( channelNb > 0 && channelNb < 5 )
    pathToFile+= convertIntToString(channelNb);
  else
    return "";

  pathToFile += "_";

  if( eventNb < 10000 )
      pathToFile+="0";
  if( eventNb < 1000 )
      pathToFile+="0";
  if( eventNb < 100 )
      pathToFile+="0";
  if( eventNb < 10 ) 
      pathToFile+="0";
  
  pathToFile += convertIntToString(eventNb);
  
  return pathToFile;
}

