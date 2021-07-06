#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <TMultiGraph.h>
#include <TGraph.h>
#include <TPaveStats.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <TH2.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TFile.h>
#include <sstream>
#include <sys/stat.h>
#include <dirent.h>
#include <TUnixSystem.h>
#include "TError.h"
#include <TAttLine.h>
#include <TPaveText.h>
#include <algorithm>
#include "TGraphErrors.h"
#include "TKey.h"
#include "TLatex.h"


using namespace std;

std::pair<double, double> FindMiddleOfComptonForCharge( TH1F* histo )
{
    TString histoName = histo->GetName();
//     cout << "\n\n" << histoName << "\n\n";
	double result; double result_error;
	int range = 13;
	range = (range - 1)/2; // how many bins to the left / right we take into average
	std::vector<double> values, counts;

    TCanvas *fitTest = new TCanvas();
    
    gStyle->SetOptFit(1111);
	
	for(Int_t i=0; i<histo->GetXaxis()->GetNbins(); i++)
    {
        counts.push_back( histo->GetBinContent(i) );
        values.push_back( histo->GetBinCenter(i) );
    }
	   
    std::vector<double> meanAveragedCounts;
    std::vector<double> meanAveragedCountsError;
    
    double error=0;
    double sum = 0.;
	for( unsigned int i=range; i<counts.size()-range; i++ )
	{
		
		 sum = 0.;
         error =0.0;
         
		 for( unsigned int j=i-range; j<i+range+1; j++ )
		 {
			  sum += counts[j];
              error+= counts[j]; 
		 }
		 		 
		 meanAveragedCounts.push_back( sum/(2*range + 1) );
         meanAveragedCountsError.push_back( TMath::Sqrt(error)/(2*range + 1) );
	}	
	
	TH1F* meanHisto = new TH1F("meanHisto","meanHisto", histo->GetNbinsX() , histo->GetXaxis()->GetXmin() , histo->GetXaxis()->GetXmax());
	for(unsigned int i = 0; i < meanAveragedCounts.size(); i++)
	{
		meanHisto->SetBinContent(i+range,meanAveragedCounts[i]);
	}
	histo->Draw();
	meanHisto->Draw("same");
	fitTest->BuildLegend();
	fitTest->SaveAs(histoName+"_meanHisto.png");
	std::vector<double> derivative;
    std::vector<double> derivativeError;
    
	for( unsigned int i=0; i<meanAveragedCounts.size()-1; i++ )
	{
		derivative.push_back( meanAveragedCounts[i+1] - meanAveragedCounts[i]);
        derivativeError.push_back( meanAveragedCountsError[i+1] + meanAveragedCountsError[i] );
	}
	
	TGraphErrors *distr2 = new TGraphErrors( derivative.size(), &values[0], &derivative[0], 0, &derivativeError[0]);
    
    int minimum =  TMath::LocMin(derivative.size(), &derivative[0]);
    std::cout << "minimum at: " << values[minimum] << std::endl;
    TF1 *parabola = new TF1("parabola", "[0]*(x-[1])**2+[2]", values[minimum - 5] , values[minimum + 5]);
    parabola-> SetParameter(0, -1);
    parabola-> SetParameter(1, values[minimum]);
    parabola-> SetParameter(2, derivative[minimum]);
    distr2->Draw("AP");
    
    distr2->Fit(parabola,"R","",values[minimum]*0.8 , values[minimum]*1.2); 
    fitTest->SaveAs(histoName+"_differential.png");    
   
    result = parabola->GetParameter(1)+range*(values[1]-values[0]);
    result_error = parabola->GetParError(1);
	delete fitTest;    
	delete distr2;
	
    return std::make_pair(result,result_error);
    
  
}

std::pair<double, double> FindMiddleOfComptonForAmplitude( TH1F* histo )
{
    TString histoName = histo->GetName();
//     cout << "\n\n" << histoName << "\n\n";
	double result; double result_error;
	int range = 13;
	range = (range - 1)/2; // how many bins to the left / right we take into average
	std::vector<double> values, counts;

    TCanvas *fitTest = new TCanvas();
    
    gStyle->SetOptFit(1111);
	
	for(Int_t i=histo->GetXaxis()->GetNbins() - 1; i>=0; i--)
    {
        counts.push_back( histo->GetBinContent(i) );
        values.push_back( - histo->GetBinCenter(i) );
    }
	   
    std::vector<double> meanAveragedCounts;
    std::vector<double> meanAveragedCountsError;
    
    double error=0;
    double sum = 0.;
	for( unsigned int i=range; i<counts.size()-range; i++ )
	{
		
		 sum = 0.;
         error =0.0;
         
		 for( unsigned int j=i-range; j<i+range+1; j++ )
		 {
			  sum += counts[j];
              error+= counts[j]; 
		 }
		 		 
		 meanAveragedCounts.push_back( sum/(2*range + 1) );
         meanAveragedCountsError.push_back( TMath::Sqrt(error)/(2*range + 1) );
	}	
	
	TH1F* meanHisto = new TH1F("meanHisto","meanHisto", histo->GetNbinsX() , histo->GetXaxis()->GetXmin() , histo->GetXaxis()->GetXmax());
	for(unsigned int i = 0; i < meanAveragedCounts.size(); i++)
	{
		meanHisto->SetBinContent(i+range,meanAveragedCounts[meanAveragedCounts.size()-i-1]);
	}
	histo->Draw();
	meanHisto->Draw("same");
	fitTest->BuildLegend();
	fitTest->SaveAs(histoName+"_meanHisto.png");
	std::vector<double> derivative;
    std::vector<double> derivativeError;
    
	for( unsigned int i=0; i<meanAveragedCounts.size()-1; i++ )
	{
		derivative.push_back( meanAveragedCounts[i+1] - meanAveragedCounts[i]);
        derivativeError.push_back( meanAveragedCountsError[i+1] + meanAveragedCountsError[i] );
	}
	
	TGraphErrors *distr2 = new TGraphErrors( derivative.size(), &values[0], &derivative[0], 0, &derivativeError[0]);
    
    int minimum =  TMath::LocMin(derivative.size(), &derivative[0]);
    std::cout << "minimum at: " << values[minimum] << std::endl;
    TF1 *parabola = new TF1("parabola", "[0]*(x-[1])**2+[2]", values[minimum - 5] , values[minimum + 5]);
    parabola-> SetParameter(0, -1);
    parabola-> SetParameter(1, values[minimum]);
    parabola-> SetParameter(2, derivative[minimum]);
    distr2->Draw("AP");
    
    distr2->Fit(parabola,"R","",values[minimum]*0.8 , values[minimum]*1.2); 
    fitTest->SaveAs(histoName+"_differential.png");    
   
    result = parabola->GetParameter(1)+range*(values[1]-values[0]);
    result_error = parabola->GetParError(1);
	delete fitTest;    
	delete distr2;
	
    return std::make_pair(-result,result_error);
    
  
}
