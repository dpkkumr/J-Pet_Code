
int producePlots(const std::string filePath)
{
	//sprawdzanie czy jest plik z wynikami, jak tak to otwieranie, jak nie to tworzenie z naglowkiem i otwieranie
    //TFile* file = TFile::Open(filePath.c_str() );
    std::ofstream ofs;

     if(gSystem->AccessPathName("results.txt")){
        std::cout << "results.txt does not exist" << std::endl;
        ofs.open("results.txt");
        ofs << "Path \t File name \t Pin \t Position \t Ampiltude 1 [mV] \t  Error \t Ampiltude 2 [mV] \t Error\t Charge 1 [pC] \t Error \t Charge 2 [pC] \t  Error \t Geometrical mean [pC] \t Error \t Aritmetical mean [pC] \t Error \t Time difference resolution [ps] \t Error" << std::endl;
    } else {
        std::cout << "results.txt exists" << std::endl;
        ofs.open("results.txt", std::ofstream::app);

    }
    



 	TString name = filePath;
	name = name.ReplaceAll(".root","");
	TFile* file = TFile::Open(filePath.c_str() );

		if( !file->IsOpen() )
		return 2;

	std::cout << name.Last('/')  << "\t" ;
	name = name(name.Last('/')+1, name.Length());
	std::cout << name << "\t";
	ofs << filePath << "\t";
	ofs << name << ".root \t" ;

	ofs << "\t";
	ofs << "\t";

	file->ls();
	TTree* dataTree = (TTree*)file->Get("signalDataTree");
	TCanvas* c1 = new TCanvas("c1","c1");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	if(dataTree==0)
	  return 1;	
    
    TString frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_Amplitude1";
    double minX = dataTree->GetMinimum("Amplitude1");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    double maxX = dataTree->GetMaximum("Amplitude1");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
    TH1D *frame = new TH1D(frameName,"frame",  160 , -800 , 0 );
	frame->GetXaxis()->SetTitle("Amplitude1 [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("Amplitude 1");
	frame->SetLineWidth(3);
	frame->SetLineColor(8);
    TString tempDrawDestination = "Amplitude1 >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	double maxCounts = frame->GetMaximum();
	TH1F* histoWithData = (TH1F*)c1->GetPrimitive(frameName);
	if(histoWithData == nullptr )
		return 3;
    histoWithData->SetName(frameName);
	std::pair<double,double> result = FindMiddleOfComptonForAmplitude(histoWithData);
	histoWithData->Draw();
	TLine* line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	TPaveText *pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    TString results;
    results.Form("Edge at %.2f +/- %.2f mV",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_Amplitude1.png" );
	c1->SaveAs( name+"_Amplitude1.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 


	frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_Amplitude2";
    minX = dataTree->GetMinimum("Amplitude2");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    maxX = dataTree->GetMaximum("Amplitude2");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
    frame = new TH1D(frameName,"frame", 160 , -800 , 0 );
	frame->GetXaxis()->SetTitle("Amplitude2 [mV]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("Amplitude 2");
	frame->SetLineWidth(3);
	frame->SetLineColor(8);
    tempDrawDestination = "Amplitude2 >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	maxCounts = frame->GetMaximum();
	histoWithData = (TH1F*)c1->GetPrimitive(frameName);
    histoWithData->SetName(frameName);
	result = FindMiddleOfComptonForAmplitude(histoWithData);
	histoWithData->Draw();
	line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    results.Form("Edge at %.2f +/- %.2f mV",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_Amplitude2.png" );
	c1->SaveAs( name+"_Amplitude2.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 


	//frame = new TH1D("frame","frame", 100 , -800. , 0. );
	//frame->GetXaxis()->SetTitle("Amplitude3 [mV]");
	//frame->GetYaxis()->SetTitle("Counts");
	//frame->SetTitle("Amplitude 3");
	//frame->SetLineWidth(3);
	//frame->SetLineColor(8);
	//dataTree->Draw("Amplitude3 >> frame");
	//c1->SaveAs( name+"_Amplitude3.png" );
	//c1->SaveAs( name+"_Amplitude3.root");
	//c1->SetCanvasSize(1000, 1000);
	//c1->SetWindowSize(1100, 1100);
	
    frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_Charge1";
    minX = dataTree->GetMinimum("Charge1");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    maxX = dataTree->GetMaximum("Charge1");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
	frame = new TH1D(frameName,"frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("Charge1 [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("Charge 1");
	frame->SetLineWidth(3);
	frame->SetLineColor(13);
    tempDrawDestination = "Charge1 >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	maxCounts = frame->GetMaximum();
	histoWithData = (TH1F*)c1->GetPrimitive(frameName);
    histoWithData->SetName(frameName);
	result = FindMiddleOfComptonForCharge(histoWithData);
	histoWithData->Draw();
	line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    results.Form("Edge at %.2f +/- %.2f pC",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_Charge1.png" );
	c1->SaveAs( name+"_Charge1.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 
	
    frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_Charge2";
    minX = dataTree->GetMinimum("Charge2");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    maxX = dataTree->GetMaximum("Charge2");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
	frame = new TH1D(frameName,"frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("Charge2 [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("Charge 2");
	frame->SetLineWidth(3);
	frame->SetLineColor(13);
    tempDrawDestination = "Charge2 >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	maxCounts = frame->GetMaximum();
	histoWithData = (TH1F*)c1->GetPrimitive(frameName);
    histoWithData->SetName(frameName);
	result = FindMiddleOfComptonForCharge(histoWithData);
	histoWithData->Draw();
	line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    results.Form("Edge at %.2f +/- %.2f pC",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_Charge2.png" );
	c1->SaveAs( name+"_Charge2.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 
	
	//frame = new TH1D("frame","frame", 100 , -0.1 , 1.5);
	//frame->GetXaxis()->SetTitle("Charge3 [pC]");
	//frame->GetYaxis()->SetTitle("Counts");
	//frame->SetTitle("Charge 3");
	//frame->SetLineWidth(3);
	//frame->SetLineColor(13);
	//dataTree->Draw("Charge3 >> frame");
	//c1->SaveAs( name+"_Charge3.png" );
	//c1->SaveAs( name+"_Charge3.root");
	//c1->SetCanvasSize(1000, 1000);
	//c1->SetWindowSize(1100, 1100);
	
    frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_ChargeSum";
    minX = dataTree->GetMinimum("(Charge1+Charge2)/2");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    maxX = dataTree->GetMaximum("(Charge1+Charge2)/2");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
	frame = new TH1D(frameName,"frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("(Charge1+Charge2)/2 [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("(Charge1+Charge2)/2 ");
	frame->SetLineWidth(3);
	frame->SetLineColor(13);
    tempDrawDestination = "(Charge1+Charge2)/2 >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	maxCounts = frame->GetMaximum();
	histoWithData = (TH1F*)c1->GetPrimitive(frameName);
    histoWithData->SetName(frameName);
	result = FindMiddleOfComptonForCharge(histoWithData);
	histoWithData->Draw();
	line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    results.Form("Edge at %.2f +/- %.2f pC",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_ChargeSum.png" );
	c1->SaveAs( name+"_ChargeSum.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 
	
	frameName = name;
	frameName = frameName.ReplaceAll(".","");
	frameName = frameName.ReplaceAll("/","");
    frameName += "_ChargeSqrt";
    minX = dataTree->GetMinimum("sqrt(Charge1*Charge2)");
    minX -= 0.05;
    minX = TMath::Nint(minX*10.)/10.;
    maxX = dataTree->GetMaximum("sqrt(Charge1*Charge2)");
    maxX += 0.05;
    maxX = TMath::Nint(maxX*10.)/10.;
	frame = new TH1D(frameName,"frame", 160 , -0.1 , 1.5);
	frame->GetXaxis()->SetTitle("sqrt(Charge1*Charge2) [pC]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle("sqrt(Charge1*Charge2)");
	frame->SetLineWidth(3);
	frame->SetLineColor(13);
    tempDrawDestination = "sqrt(Charge1*Charge2) >> ";
    tempDrawDestination += frameName;
	dataTree->Draw(tempDrawDestination);
	maxCounts = frame->GetMaximum();
	histoWithData = (TH1F*)c1->GetPrimitive(frameName);
    histoWithData->SetName(frameName);
	result = FindMiddleOfComptonForCharge(histoWithData);
	histoWithData->Draw();
	line = new TLine(result.first, 0, result.first, maxCounts);
	line->Draw();
	line->SetLineWidth(3);
	line->SetLineColor(2);
	pt = new TPaveText(0.98,0.55,0.78,0.65, "NDC");
    results.Form("Edge at %.2f +/- %.2f pC",TMath::Nint(result.first*100.)/100.,TMath::Nint(result.second*100.)/100.);
	pt->AddText(results);
	pt->Draw();
	c1->SaveAs( name+"_ChargeSqrt.png" );
	c1->SaveAs( name+"_ChargeSqrt.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	ofs << result.first << "\t" << result.second << "\t" ; 
	
	
	frame = new TH1D("frame","frame", 200 , -10. , 10.);
	frame->GetXaxis()->SetTitle("TimeAtThr1 - TimeAtThr2 [ns]");
	frame->GetYaxis()->SetTitle("Counts");
	frame->SetTitle( "TimeAtThr1 - TimeAtThr2 [25% Fraction]");
	frame->SetLineWidth(3);
	frame->SetLineColor(4);
	dataTree->Draw("TimeAtThr1 - TimeAtThr2 >>  frame ");
	double max = frame->GetXaxis()->GetBinCenter( frame->GetMaximumBin() );
        Double_t par[6];
        TF1* poly2 = new TF1("poly2", "pol2", max-6, max-3);
        frame->Fit("poly2","RIEM");
        poly2->GetParameters(&par[0]);
        TF1* g = new TF1("g", "gaus", max+1, max-1 );
        frame->Fit("g","RIEM");
        g->GetParameters(&par[3]);

        TF1* sum = new TF1("sum", "pol2(0)+gaus(3)", max-5, max+5);
        sum->SetParameters(par);
        frame->Fit("sum", "RIEM");


	
	gStyle->SetOptFit(1);
	c1->SaveAs( name+"_timeDiffNoCut.png" );
	c1->SaveAs( name+"_timeDiffNoCut.root");
	c1->SetCanvasSize(1000, 1000);
	c1->SetWindowSize(1100, 1100);
	double parameter = sum->GetParameter(5);
	double Errorparameter = sum->GetParError(5);
	ofs <<  parameter *1000.0 << "\t";
	ofs <<  Errorparameter  *1000 << std::endl;
	

	ofs.close();

	return 0;
}
