#include "signalDataTree.h"


bool signalDataTree::fill()
{
  if( fBaseline1 != 666.666 && fBaseline2 != 666.666 )
  {
	  if( fCharge1 != 0 && fCharge2 != 0  )
	  {
		  if( fTimeAtThr1 != 999 && fTimeAtThr2 != 999 )
		  {
			    fTree->Fill(); 
			  
		  }
	  }
  }
  fCharge1 = fCharge2 = fCharge3 = 0;
  fAmplitude1 = fAmplitude2 = fAmplitude3 = 0;
  fBaseline1 = fBaseline2 = fBaseline3 = 0;
  fTimeAtThr1 = fTimeAtThr2 = fTimeAtThr3 = 0;
  fRiseTime1 = fRiseTime2 = fRiseTime3 = 0;
  fFallTime1 = fFallTime2 = fFallTime3 = 0;
  return true; 
}

bool signalDataTree::setFileNumber(int number)
{
  fFileNumber = number;
  return true;
}

bool signalDataTree::setCharge(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fCharge1 = value;
	   break;
        case 2:
	   fCharge2 = value;
	   break;
        case 3:
	   fCharge3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

bool signalDataTree::setAmplitude(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fAmplitude1 = value;
	   break;
        case 2:
	   fAmplitude2 = value;
	   break;
        case 3:
	   fAmplitude3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

bool signalDataTree::setRiseTime(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fRiseTime1 = value;
	   break;
        case 2:
	   fRiseTime2 = value;
	   break;
        case 3:
	   fRiseTime3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

bool signalDataTree::setFallTime(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fFallTime1 = value;
	   break;
        case 2:
	   fFallTime2 = value;
	   break;
        case 3:
	   fFallTime3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

bool signalDataTree::setBaseline(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fBaseline1 = value;
	   break;
        case 2:
	   fBaseline2 = value;
	   break;
        case 3:
	   fBaseline3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

bool signalDataTree::setTimeAtThr(double value, int channel)
{
   bool goodChannel = true;
   switch(channel){
	case 1:
	   fTimeAtThr1 = value;
	   break;
        case 2:
	   fTimeAtThr2 = value;
	   break;
        case 3:
	   fTimeAtThr3 = value;
	   break;
	default:
	   goodChannel = false;
   }
   return goodChannel;
}

signalDataTree::~signalDataTree()
{
    f2->Write();
    f2->Close();
}

signalDataTree::signalDataTree(std::string outputName)
{
  f2 = new TFile ( outputName.c_str() , "recreate");
  fTree=new TTree("signalDataTree","signalDataTree");
  fTree-> Branch ("File_number", &fFileNumber);
  fTree-> Branch ("Amplitude1", &fAmplitude1);
  fTree-> Branch ("Amplitude2", &fAmplitude2);
  fTree-> Branch ("Amplitude3", &fAmplitude3);
  fTree-> Branch ("Baseline1", &fBaseline1);
  fTree-> Branch ("Baseline2", &fBaseline2);
  fTree-> Branch ("Baseline3", &fBaseline3);
  fTree-> Branch ("Charge1", &fCharge1);
  fTree-> Branch ("Charge2", &fCharge2);
  fTree-> Branch ("Charge3", &fCharge3);
  fTree-> Branch ("RiseTime1From20Pto80P", &fRiseTime1);
  fTree-> Branch ("RiseTime2From20Pto80P", &fRiseTime2);
  fTree-> Branch ("RiseTime3From20Pto80P", &fRiseTime3);
  fTree-> Branch ("FallTime1From10Pto90P", &fFallTime1);
  fTree-> Branch ("FallTime2From10Pto90P", &fFallTime2);
  fTree-> Branch ("FallTime3From10Pto90P", &fFallTime3);
  fTree-> Branch ("TimeAtThr1", &fTimeAtThr1);
  fTree-> Branch ("TimeAtThr2", &fTimeAtThr2);
  fTree-> Branch ("TimeAtThr3", &fTimeAtThr3);
  fTree-> Branch ("ERRORflag1", &ERRORflag1);
  fTree-> Branch ("ERRORflag2", &ERRORflag2);
  fTree-> Branch ("ERRORflag3", &ERRORflag3);

}
