// In order to run:
// .L comparePlots.cpp
// compareThreePlots("Left.root","Center.root","Right.root")


int compareFourPlots(const std::string filePath_First, const std::string filePath_Second, const std::string filePath_Third, const std::string filePath_Four)
{
 	TString name_First = filePath_First;
	name_First = name_First.ReplaceAll(".root","");
	TFile* file_First = TFile::Open(filePath_First.c_str() );

	file_First->ls();
	TTree* dataTree_First = (TTree*)file_First->Get("signalDataTree");
    
    TString name_Second = filePath_Second;
	name_Second = name_Second.ReplaceAll(".root","");
	TFile* file_Second = TFile::Open(filePath_Second.c_str() );

	file_Second->ls();
	TTree* dataTree_Second = (TTree*)file_Second->Get("signalDataTree");
    
    TString name_Third = filePath_Third;
	name_Third = name_Third.ReplaceAll(".root","");
	TFile* file_Third = TFile::Open(filePath_Third.c_str() );

	file_Third->ls();
	TTree* dataTree_Third = (TTree*)file_Third->Get("signalDataTree");
	
    TString name_Four = filePath_Four;
	name_Four = name_Four.ReplaceAll(".root","");
	TFile* file_Four = TFile::Open(filePath_Four.c_str() );

	file_Four->ls();
	TTree* dataTree_Four = (TTree*)file_Four->Get("signalDataTree");


    TCanvas* c1 = new TCanvas("c1","c1");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
	
    
    //=================================================================================================
    
    TH1D *frame = new TH1D("frame","frame", 200 , -1000. , 0. );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparison_C1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    TH1D *frame2 = new TH1D("frame2","frame2", 200 , -1000. , 0. );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparison_C1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    TH1D *frame3 = new TH1D("frame3","frame3", 200 , -1000 , 0. );
	frame3->GetXaxis()->SetTitle("Amplitude [mV]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("AmplitudeComparison_C1");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);

    TH1D *frame4 = new TH1D("frame4","frame4", 200 , -1000 , 0. );
	frame4->GetXaxis()->SetTitle("Amplitude [mV]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("AmplitudeComparison_C1");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);
    
    gStyle->SetOptStat(0);
	
	dataTree_First->Draw("Amplitude1 >> frame","","");
    dataTree_Second->Draw("Amplitude1 >> frame2","","same");
	dataTree_Third->Draw("Amplitude1 >> frame3","","same");
	dataTree_Four->Draw("Amplitude1 >> frame4","","same");

    
    TLegend *legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "AmplitudeComparison_C1.png" );
	c1->SaveAs( "AmplitudeComparison_C1.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 200 , -1000 , 0. );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparison_C2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 200 , -1000 , 0. );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparison_C2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 200 , -1000 , 0. );
	frame3->GetXaxis()->SetTitle("Amplitude [mV]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("AmplitudeComparison_C2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
	
    frame4 = new TH1D("frame4","frame4", 200 , -1000 , 0. );
	frame4->GetXaxis()->SetTitle("Amplitude [mV]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("AmplitudeComparison_C2");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);
    
    gStyle->SetOptStat(0);
	
    dataTree_First->Draw("Amplitude2 >> frame","","");
	dataTree_Second->Draw("Amplitude2 >> frame2","","same");
	dataTree_Third->Draw("Amplitude2 >> frame3","","same");
	dataTree_Four->Draw("Amplitude2 >> frame4","","same");
    
    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "AmplitudeComparison_C2.png" );
	c1->SaveAs( "AmplitudeComparison_C2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 160 , -0.1, 1.5);
	frame->GetXaxis()->SetTitle("Charge [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("ChargeComparison_C2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 160 , -0.1 , 1.5);
	frame2->GetXaxis()->SetTitle("Charge [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("ChargeComparison_C2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 160 , -0.1 , 1.5);
	frame3->GetXaxis()->SetTitle("Charge [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("ChargeComparison_C2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    frame4 = new TH1D("frame4","frame4", 160 , -0.1 , 1.5 );
	frame4->GetXaxis()->SetTitle("Charge [pC]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("ChargeComparison_C2");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);

    gStyle->SetOptStat(0);
	
    dataTree_First->Draw("Charge2 >> frame","","");
	dataTree_Second->Draw("Charge2 >> frame2","","same");
	dataTree_Third->Draw("Charge2 >> frame3","","same");
	dataTree_Four->Draw("Charge2 >> frame4","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "ChargeComparison_C2.png" );
	c1->SaveAs( "ChargeComparison_C2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 140 , 30. , 0.5);
	frame->GetXaxis()->SetTitle("Charge [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("ChargeComparison_C1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 140 , 30. , 0.5);
	frame2->GetXaxis()->SetTitle("Charge [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("ChargeComparison_C1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 140 , 30. , 0.5);
	frame3->GetXaxis()->SetTitle("Charge [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("ChargeComparison_C1");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);

    frame4 = new TH1D("frame4","frame4", 140 , 30. , 0.5 );
	frame4->GetXaxis()->SetTitle("Charge [pC]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("ChargeComparison_C1");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);
    
    gStyle->SetOptStat(0);
	
	dataTree_First->Draw("Charge1 >> frame","","");
    dataTree_Second->Draw("Charge1 >> frame2","","same");
	dataTree_Third->Draw("Charge1 >> frame3","","same");
	dataTree_Four->Draw("Charge1 >> frame4","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "ChargeComparison_C1.png" );
	c1->SaveAs( "ChargeComparison_C1.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("(Charge1+Charge2)/2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 160 , -0.1 , 1.5);
	frame2->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("(Charge1+Charge2)/2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 160 , -0.1 , 1.5);
	frame3->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("(Charge1+Charge2)/2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    frame4 = new TH1D("frame4","frame4", 160 , -0.1 , 1.5);
	frame4->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("(Charge1+Charge2)/2");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);

    gStyle->SetOptStat(0);
	
	dataTree_First->Draw("(Charge1+Charge2)/2 >> frame","","");
    dataTree_Second->Draw("(Charge1+Charge2)/2 >> frame2","","same");
	dataTree_Third->Draw("(Charge1+Charge2)/2 >> frame3","","same");
	dataTree_Four->Draw("(Charge1+Charge2)/2 >> frame4","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "ChargeSumComparison.png" );
	c1->SaveAs( "ChargeSumComparison.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("sqrt(Charge1*Charge2)");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 160 , -0.1 , 1.5);
	frame2->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("sqrt(Charge1*Charge2)");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 160 , -0.1 , 1.5);
	frame3->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("sqrt(Charge1*Charge2)");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    frame4 = new TH1D("frame4","frame4", 160 , -0.1 , 1.5);
	frame4->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("sqrt(Charge1*Charge2)");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);

    gStyle->SetOptStat(0);
	
	dataTree_First->Draw("sqrt(Charge1*Charge2) >> frame","","");
    dataTree_Second->Draw("sqrt(Charge1*Charge2) >> frame2","","same");
	dataTree_Third->Draw("sqrt(Charge1*Charge2) >> frame3","","same");
	dataTree_Four->Draw("sqrt(Charge1*Charge2) >> frame4","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "ChargeSqrtComparison.png" );
	c1->SaveAs( "ChargeSqrtComparison.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 200 , -10. , 10.);
	frame->GetXaxis()->SetTitle("TimeAtThr1 - TimeAtThr2 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("TimeAtThr1 - TimeAtThr2 [25\% Fraction]");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 200 , -10. , 10.);
	frame2->GetXaxis()->SetTitle("TimeAtThr1 - TimeAtThr2 [ns]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("TimeAtThr1 - TimeAtThr2 [25\% Fraction]");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 200 , -10. , 10.);
	frame3->GetXaxis()->SetTitle("TimeAtThr1 - TimeAtThr2 [ns]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("TimeAtThr1 - TimeAtThr2 [25\% Fraction]");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    frame4 = new TH1D("frame4","frame4", 200 , -10. , 10. );
	frame4->GetXaxis()->SetTitle("TimeAtThr1 - TimeAtThr2 [ns] [ns]");
	frame4->GetYaxis()->SetTitle("Counts");
	frame4->SetTitle("TimeAtThr1 - TimeAtThr2 [25\% Fraction]");
	frame4->SetLineWidth(3);
	frame4->SetLineColor(kBlack);

    gStyle->SetOptStat(0);
	
	dataTree_First->Draw("TimeAtThr1 - TimeAtThr2 >> frame","","");
    dataTree_Second->Draw("TimeAtThr1 - TimeAtThr2 >> frame2","","same");
	dataTree_Third->Draw("TimeAtThr1 - TimeAtThr2 >> frame3","","same");
	dataTree_Four->Draw("TimeAtThr1 - TimeAtThr2 >> frame4","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,name_First ,"l");
    legend->AddEntry(frame2, name_Second ,"l");
    legend->AddEntry(frame3, name_Third ,"l");
    legend->AddEntry(frame4, name_Four ,"l");

    legend->Draw();
    
	c1->SaveAs( "timeDiffNoCutComparison.png" );
	c1->SaveAs( "timeDiffNoCutComparison.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================

	return 0;
}
