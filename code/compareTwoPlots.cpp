// In order to run:
// .L comparePlots.cpp
// compareTwoPlots("Left.root","Center.root")


int compareTwoPlots(const std::string filePath_Left, const std::string filePath_Center)
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

    TCanvas* c1 = new TCanvas("c1","c1");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);


    //=================================================================================================

    TH1D *frame = new TH1D("frame","frame", 200 , -1000 , 0 );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparisonC1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    TH1D *frame2 = new TH1D("frame2","frame2", 200 , -800 , 0 );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparisonC1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("Amplitude1 >> frame","","");
    dataTree_Center->Draw("Amplitude1 >> frame2","","same");

    TLegend *legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "AmplitudeComparisonC1.png" );
	c1->SaveAs( "AmplitudeComparisonC1.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);

    //=================================================================================================

    //=================================================================================================

    frame = new TH1D("frame","frame", 160 , -800 , 0 );
	frame->GetXaxis()->SetTitle("Amplitude [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("AmplitudeComparison_C2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 160 , -800 , 0 );
	frame2->GetXaxis()->SetTitle("Amplitude [mV]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("AmplitudeComparison_C2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("Amplitude2 >> frame","","");
	dataTree_Center->Draw("Amplitude2 >> frame2","","same");

    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "AmplitudeComparison_C2.png" );
	c1->SaveAs( "AmplitudeComparison_C2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);

    //=================================================================================================

    frame = new TH1D("frame","frame", 150 , 0. , 15. );
	frame->GetXaxis()->SetTitle("Rise time .2-.8 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("RiseTimeComparison_C2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 150 , 0. , 15. );
	frame2->GetXaxis()->SetTitle("Rise time .2-.8 [ns]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("RiseTimeComparison_C2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("RiseTime2From20Pto80P >> frame","","");
	dataTree_Center->Draw("RiseTime2From20Pto80P >> frame2","","same");

    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "RiseTimeComparison_C2.png" );
	c1->SaveAs( "RiseTimeComparison_C2.root");


    //=================================================================================================

    frame = new TH1D("frame","frame", 150 , 0. , 15.);
	frame->GetXaxis()->SetTitle("Rise time .2-.8 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("RiseTimeComparison_C1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 150 , 0. , 15. );
	frame2->GetXaxis()->SetTitle("Rise time .2-.8 [ns]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("RiseTimeComparison_C1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("RiseTime1From20Pto80P >> frame","","");
	dataTree_Center->Draw("RiseTime1From20Pto80P >> frame2","","same");

    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "RiseTimeComparison_C1.png" );
	c1->SaveAs( "RiseTimeComparison_C1.root");

    //=================================================================================================

    frame = new TH1D("frame","frame", 140 , 30. , 100. );
	frame->GetXaxis()->SetTitle("Fall time .9-.1 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("FallTimeComparison_C2");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 140 , 30. , 100. );
	frame2->GetXaxis()->SetTitle("Fall time .9-.1 [ns]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("FallTimeComparison_C2");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("FallTime2From10Pto90P >> frame","","");
	dataTree_Center->Draw("FallTime2From10Pto90P >> frame2","","same");

    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "FallTimeComparison_C2.png" );
	c1->SaveAs( "FallTimeComparison_C2.root");


    //=================================================================================================

    frame = new TH1D("frame","frame", 140 , 30. , 100. );
	frame->GetXaxis()->SetTitle("Rise time .9-.1 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("FallTimeComparison_C1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 140 , 30. , 100. );
	frame2->GetXaxis()->SetTitle("Fall time .1-.9 [ns]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("FallTimeComparison_C1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("FallTime1From10Pto90P >> frame","","");
	dataTree_Center->Draw("FallTime1From10Pto90P >> frame2","","same");

    legend = new TLegend(0.1,0.7,0.4,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "FallTimeComparison_C1.png" );
	c1->SaveAs( "FallTimeComparison_C1.root");

    //=================================================================================================

    frame = new TH1D("frame","frame", 160 , -0.1 , 1.5);
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

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("Charge2 >> frame","","");
	dataTree_Center->Draw("Charge2 >> frame2","","same");

    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "ChargeComparison_C2.png" );
	c1->SaveAs( "ChargeComparison_C2.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);

    //=================================================================================================

    //=================================================================================================

    frame = new TH1D("frame","frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("Charge [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("ChargeComparison_C1");
	frame->SetLineWidth(3);
	frame->SetLineColor(kBlue);

    frame2 = new TH1D("frame2","frame2", 160 , -0.1 , 1.5);
	frame2->GetXaxis()->SetTitle("Charge [pC]");
	frame2->GetYaxis()->SetTitle("Counts");
	frame2->SetTitle("ChargeComparison_C1");
	frame2->SetLineWidth(3);
	frame2->SetLineColor(kRed);

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("Charge1 >> frame","","");
	dataTree_Center->Draw("Charge1 >> frame2","","same");

    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

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

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("(Charge1+Charge2)/2 >> frame","","");
	dataTree_Center->Draw("(Charge1+Charge2)/2 >> frame2","","same");

    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

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

    gStyle->SetOptStat(0);

    dataTree_Left->Draw("sqrt(Charge1*Charge2) >> frame","","");
	dataTree_Center->Draw("sqrt(Charge1*Charge2) >> frame2","","same");

    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

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

    gStyle->SetOptStat(0);

	dataTree_Center->Draw("TimeAtThr1 - TimeAtThr2 >> frame2","","");
    dataTree_Left->Draw("TimeAtThr1 - TimeAtThr2 >> frame","","same");

    legend = new TLegend(0.6,0.7,0.9,0.9);
    legend->AddEntry(frame, filePath_Left.c_str(),"l");
    legend->AddEntry(frame2, filePath_Center.c_str(),"l");

    legend->Draw();

	c1->SaveAs( "timeDiffNoCutComparison.png" );
	c1->SaveAs( "timeDiffNoCutComparison.root");
// 	c1->SetCanvasSize(1000, 1000);
// 	c1->SetWindowSize(1100, 1100);

    //=================================================================================================

	return 0;
}
