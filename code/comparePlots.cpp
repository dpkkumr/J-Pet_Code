// In order to run:
// .L comparePlots.cpp
// compareThreePlots("Left.root","Center.root","Right.root")


int compareThreePlots(const std::string filePath_Left, const std::string filePath_Center, const std::string filePath_Right)
{
 	TString name_Left = filePath_Left;
	name_Left = name_Left.ReplaceAll(".root","");
	TFile* file_Left = TFile::Open(filePath_Left.c_str() );

	file_Left->ls();
	TTree* dataTree_Left = (TTree*)file_Left->Get("signalDataTree");
    
    TString name_Center = filePath_Center;
	name_Center = name_Center.ReplaceAll(".root","");
	TFile* file_Center = TFile::Open(filePath_Center.c_str() );

	file_Center->ls();
	TTree* dataTree_Center = (TTree*)file_Center->Get("signalDataTree");
    
    TString name_Right = filePath_Right;
	name_Right = name_Right.ReplaceAll(".root","");
	TFile* file_Right = TFile::Open(filePath_Right.c_str() );

	file_Right->ls();
	TTree* dataTree_Right = (TTree*)file_Right->Get("signalDataTree");
	
    TCanvas* c1 = new TCanvas("c1","c1");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
	
    
    //=================================================================================================
    
    TH1D *frame = new TH1D("frame","frame", 100 , -500. , 0. );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparison_L1C1R2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    TH1D *frame2 = new TH1D("frame2","frame2", 100 , -500. , 0. );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparison_L1C1R2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    TH1D *frame3 = new TH1D("frame3","frame3", 100 , -500. , 0. );
	frame3->GetXaxis()->SetTitle("Amplitude [mV]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("AmplitudeComparison_L1C1R2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
	dataTree_Right->Draw("Amplitude2 >> frame3","","");
    dataTree_Left->Draw("Amplitude1 >> frame","","same");
	dataTree_Center->Draw("Amplitude1 >> frame2","","same");
    
    TLegend *legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "AmplitudeComparison_L1C1R2.png" );
	c1->SaveAs( "AmplitudeComparison_L1C1R2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 100 , -500. , 0. );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparison_L2C2R1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 100 , -500. , 0. );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparison_L2C2R1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 100 , -500. , 0. );
	frame3->GetXaxis()->SetTitle("Amplitude [mV]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("AmplitudeComparison_L2C2R1");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
    dataTree_Left->Draw("Amplitude2 >> frame","","");
	dataTree_Right->Draw("Amplitude1 >> frame3","","same");
	dataTree_Center->Draw("Amplitude2 >> frame2","","same");
    
    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "AmplitudeComparison_L2C2R1.png" );
	c1->SaveAs( "AmplitudeComparison_L2C2R1.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 100 , -0.1 , 0.5);
	frame->GetXaxis()->SetTitle("Charge [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("ChargeComparison_L2C2R1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 100 , -0.1 , 0.5);
	frame2->GetXaxis()->SetTitle("Charge [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("ChargeComparison_L2C2R1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 100 , -0.1 , 0.5);
	frame3->GetXaxis()->SetTitle("Charge [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("ChargeComparison_L2C2R1");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
    dataTree_Left->Draw("Charge2 >> frame","","");
	dataTree_Right->Draw("Charge1 >> frame3","","same");
	dataTree_Center->Draw("Charge2 >> frame2","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "ChargeComparison_L2C2R1.png" );
	c1->SaveAs( "ChargeComparison_L2C2R1.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 100 , -0.1 , 0.5);
	frame->GetXaxis()->SetTitle("Charge [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("ChargeComparison_L1C1R2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 100 , -0.1 , 0.5);
	frame2->GetXaxis()->SetTitle("Charge [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("ChargeComparison_L1C1R2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 100 , -0.1 , 0.5);
	frame3->GetXaxis()->SetTitle("Charge [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("ChargeComparison_L1C1R2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
	dataTree_Right->Draw("Charge2 >> frame3","","");
    dataTree_Left->Draw("Charge1 >> frame","","same");
	dataTree_Center->Draw("Charge1 >> frame2","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "ChargeComparison_L1C1R2.png" );
	c1->SaveAs( "ChargeComparison_L1C1R2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 100 , -0.1 , 0.5);
	frame->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("(Charge1+Charge2)/2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 100 , -0.1 , 0.5);
	frame2->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("(Charge1+Charge2)/2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 100 , -0.1 , 0.5);
	frame3->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("(Charge1+Charge2)/2");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
	dataTree_Right->Draw("(Charge1+Charge2)/2 >> frame3","","");
    dataTree_Left->Draw("(Charge1+Charge2)/2 >> frame","","same");
	dataTree_Center->Draw("(Charge1+Charge2)/2 >> frame2","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "ChargeSumComparison.png" );
	c1->SaveAs( "ChargeSumComparison.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================
    
    //=================================================================================================
    
    frame = new TH1D("frame","frame", 100 , -0.1 , 0.5);
	frame->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("sqrt(Charge1*Charge2)");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);
    
    frame2 = new TH1D("frame2","frame2", 100 , -0.1 , 0.5);
	frame2->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("sqrt(Charge1*Charge2)");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);
    
    frame3 = new TH1D("frame3","frame3", 100 , -0.1 , 0.5);
	frame3->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame3->GetYaxis()->SetTitle("Counts");
	frame3->SetTitle("sqrt(Charge1*Charge2)");
	frame3->SetLineWidth(3);
	frame3->SetLineColor(kGreen);
    
    gStyle->SetOptStat(0);
	
	dataTree_Right->Draw("sqrt(Charge1*Charge2) >> frame3","","");
    dataTree_Left->Draw("sqrt(Charge1*Charge2) >> frame","","same");
	dataTree_Center->Draw("sqrt(Charge1*Charge2) >> frame2","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

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
    
    gStyle->SetOptStat(0);
	
	dataTree_Center->Draw("TimeAtThr1 - TimeAtThr2 >> frame2","","");
    dataTree_Left->Draw("TimeAtThr1 - TimeAtThr2 >> frame","","same");
	dataTree_Right->Draw("TimeAtThr1 - TimeAtThr2 >> frame3","","same");
    
    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame,"Left.root","l");
    legend->AddEntry(frame2,"Center.root","l");
    legend->AddEntry(frame3,"Right.root","l");

    legend->Draw();
    
	c1->SaveAs( "timeDiffNoCut.png" );
	c1->SaveAs( "timeDiffNoCut.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);
    
    //=================================================================================================

	return 0;
}
