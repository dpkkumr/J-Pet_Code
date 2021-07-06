#include "SignalAnalysisTools.h"


double signalAnalysisTools::calculateConstantThreshold(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold)
	{
	double timeAtThr = 999;
        std::vector<double> amplitudePoints = data.second;
        std::vector<double> timePoints = data.first;
	double thresholdPlusOffset = threshold;// + signal.getOffset();
	double slope=1;
    	double intercept=0;
	int indexAtMin = findIndexAtValue(min(amplitudePoints),amplitudePoints);
        int justBeforeSignal = indexAtMin - 5000;
	    
	 //DEBUG STUFF
	 /*
	    std::cout << "point number " << findIndexAtValue(min(amplitudePoints),amplitudePoints) << std::endl;
	    std::cout << "amplitude " << min(amplitudePoints) << std::endl;
            std::cout << "amplitude before signal: " << amplitudePoints[justBeforeSignal] << std::endl;
	*/
	if( justBeforeSignal < 0 )
	  justBeforeSignal = 0;
	  for(int i= justBeforeSignal ; i < indexAtMin ; i++){

			if(amplitudePoints[i+1]<thresholdPlusOffset&&amplitudePoints[i]>thresholdPlusOffset){
				slope= (amplitudePoints[i+1]-amplitudePoints[i])/(timePoints[i+1]-timePoints[i]);
				intercept=amplitudePoints[i]-(amplitudePoints[i+1]-amplitudePoints[i])/(timePoints[i+1]-timePoints[i])*timePoints[i];
		   		 timeAtThr=(thresholdPlusOffset-intercept)/slope;
		    	break;
			}
	    }
	    return timeAtThr;
	}

double signalAnalysisTools::calculateBaseline(std::vector<double>& amplitudePoints)
{
	//Finding place where minimum of signal is
	const int indexAtMinimumOfSignal = findIndexAtValue( min(amplitudePoints), amplitudePoints);
	
	//Checking if index was calculated correctly
	if(indexAtMinimumOfSignal == -666)
	{
		return 666.666;
	}

	const int numberOfPointsTakenForAproximation = 20;
	//Checking if minimum was not in first 20 points, which means that signal was not aquisited properly
	if( indexAtMinimumOfSignal < numberOfPointsTakenForAproximation )
	{
		return 666.666;
	}

	//Calculating approximate mean and std deviation of noise, estimating on numberOfPointsTakenForAproximation points
	double first20PointsMean = calculateArithmeticMean( amplitudePoints, numberOfPointsTakenForAproximation );
	double first20PointsDeviation = calculateStandardDeviation( amplitudePoints, numberOfPointsTakenForAproximation );

	//Start searching for last point in noise, go point by point to left from minium on signal
	//as long as noise will be found
	int index = indexAtMinimumOfSignal;
	while(index > numberOfPointsTakenForAproximation)
	{		
		if( isPointFromRecoSignalInNoise( first20PointsMean, first20PointsDeviation, amplitudePoints[index] ) )
		{	
			return calculateArithmeticMean( amplitudePoints, index ); // TU POPRAWIC ARITHEMTIC MEAN
		}
	index-=1;
	}
	
	return first20PointsMean;
}

int signalAnalysisTools::findIndexAtValue(double value, std::vector<double>& vector)
{
	double epsilon = 0.001;
	for(unsigned int index = 0; index < vector.size(); ++index)
	{
		if( absolute(vector[index] - value) < epsilon )
		{
			return index;
			
		}
	}
	
	return -666;
}

double signalAnalysisTools::calculateArithmeticMean(const std::vector<double>& vector, const int upToIndex)
{
	double mean = 0;
	for( int index = 0; index < upToIndex+1; ++index)
	{
		mean+=vector[index];
	}
	return mean/(upToIndex+1);
}

double signalAnalysisTools::calculateStandardDeviation(const std::vector<double>& vector, const int upToIndex)
{
	if(vector.size() == 1)
	{
		std::cout<<"Cannot calculate standard deviation for this vector!\n";
		return -1;
	}
	
	double mean = calculateArithmeticMean(vector, vector.size() -1);
	double deviation = 0;
	for( int index = 0; index < upToIndex+1; ++index)
	{
		deviation += pow( (vector[index] - mean) , 2 );
		
	}
	return pow(deviation / ( (upToIndex+1) * (upToIndex ) ), 0.5);
}

bool signalAnalysisTools::isPointFromRecoSignalInNoise(const double noiseMean, const double noiseDeviation, const double point)
{
	const double topBorder = noiseMean + 3*noiseDeviation;
	const double bottomBorder = noiseMean - 3*noiseDeviation;
	return ( ( point < topBorder ) && ( point > bottomBorder ) );
}

double signalAnalysisTools::min(const std::vector<double>& vector)
{
	if(vector.size() == 0)
	{
		std::cout<<"Vector size is 0, not possible to look for minimum\n";
		return -666;
	}
	double min = vector[0] ;
	for(unsigned int i = 1; i < vector.size(); ++i)
	{
		if( min > vector[i] )
		{
			min = vector[i];
		}
	}
	return min;
}

double signalAnalysisTools::absolute(const double number)
{
	if( number > 0 )
	{
		return number;
	}
	else return number * -1;
}


double signalAnalysisTools::calculateAreaFromStartingIndex(std::pair<std::vector<double>, std::vector<double> >& data, double offset)
{
	if(offset == 666.666)
	{
		return 0;
	}
		
		std::vector<double> amplitudePoints = data.second;
		std::vector<double> timePoints = data.first;
		int startingIndex = findStartingIndex(amplitudePoints);
		//int endingIndex = findEndingIndex(amplitudePoints, offset);
		int endingIndex = amplitudePoints.size();
		
		if(startingIndex == -666 || endingIndex == -666)
		{
			return 0;
		}
		
	double area = 0;
	for(unsigned int i=startingIndex; i< endingIndex; i++){
		  if( (amplitudePoints[i]>0 && amplitudePoints[i+1]<0) || (amplitudePoints[i]<0 && amplitudePoints[i+1]>0) )
		  {    
			  double xZero = pktPrzecieciaOX(timePoints[i],amplitudePoints[i],timePoints[i+1],amplitudePoints[i+1]);
			  if(amplitudePoints[i]>0 && amplitudePoints[i+1]<0){
				  area = area + 0.5*(xZero-timePoints[i])*amplitudePoints[i] + 0.5*(timePoints[i+1]-xZero)*amplitudePoints[i+1];  
			  }    
			  if(amplitudePoints[i]<0 && amplitudePoints[i+1]>0){
				  area = area + 0.5*(xZero-timePoints[i])*amplitudePoints[i] + 0.5*(timePoints[i+1]-xZero)*amplitudePoints[i+1];   
				  }    
			  }    
     
		  else{
			  if(amplitudePoints[i]<amplitudePoints[i+1]){      // different slopes
				  area = area + amplitudePoints[i]*(timePoints[i+1]-timePoints[i]) + 0.5*(amplitudePoints[i+1]-amplitudePoints[i])*(timePoints[i+1]-timePoints[i]);
			  }    
			  else{
				  area = area + amplitudePoints[i+1]*(timePoints[i+1]-timePoints[i]) + 0.5*(amplitudePoints[i]-amplitudePoints[i+1])*(timePoints[i+1]-timePoints[i]);
				  }    
			  	}     
			  }    

		const double resistance = 50 ; //Ohms
		area = area / resistance / 1000; //50 ohms resistance and units change to pC from m * p t
		
		return area*-1;
	}
	

double signalAnalysisTools::pktPrzecieciaOX(double x1, double y1, double x2, double y2)
{
	double slope;
	double intercept;
	slope= (y1-y2)/(x1-x2);
	intercept=y2-(y1-y2)/(x1-x2)*x2;
	//std::cout<<"Wzór ax+b: "<<slope<<"*x+"<<intercept<<std::endl;
	return -intercept/slope;
}

int signalAnalysisTools::findEndingIndex(std::vector<double>& amplitudePoints, double baseline)
	{
		//Finding place where minimum of signal is
		const int numberOfPointsTakenForAproximation = 20;
		int indexAtMinimumOfSignal = findIndexAtValue( min(amplitudePoints), amplitudePoints);
		double first20PointsDeviation = calculateStandardDeviation( amplitudePoints, numberOfPointsTakenForAproximation );
		
		//Checking if index was calculated correctly
		
		if(indexAtMinimumOfSignal == -666)
		{
			std::cout<<"Problem with finding proper index at findStartingIndex\n";
			return -666;
		}
		
		//Checking if minimum was not in first 20 points, which means that signal was not aquisited properly
		if( indexAtMinimumOfSignal < 20 )
		{
			std::cout<<"Bad signal found\n";
			return -666;
		}
		
		//Start searching for last point in noise, go point by point to left from minium on signal
		//as long as noise will be found
		
		int index = indexAtMinimumOfSignal;
		while(index < amplitudePoints.size()-1)
		{		
			if( isPointFromRecoSignalInNoise( baseline, first20PointsDeviation , amplitudePoints[index] ) )
			{
				return index;
			}
			index+=1;
		}
		return -666;
	}

int signalAnalysisTools::findStartingIndex(std::vector<double>& amplitudePoints)
	{
		//Finding place where minimum of signal is
		int indexAtMinimumOfSignal = findIndexAtValue( min(amplitudePoints), amplitudePoints);
		
		//Calculating approximate mean and std deviation of noise, estimating on first 20 points
		const int numberOfPointsTakenForAproximation = 20;
		double first20PointsMean = calculateArithmeticMean( amplitudePoints, numberOfPointsTakenForAproximation );
		double first20PointsDeviation = calculateStandardDeviation( amplitudePoints, numberOfPointsTakenForAproximation );
		
		//Checking if index was calculated correctly
		
		if(indexAtMinimumOfSignal == -666)
		{
			std::cout<<"Problem with finding proper index at findStartingIndex\n";
			return -666;
		}
		
		//Checking if minimum was not in first 20 points, which means that signal was not aquisited properly
		if( indexAtMinimumOfSignal < numberOfPointsTakenForAproximation )
		{
			std::cout<<"Bad signal found\n";
			return -666;
		}
		
		//Start searching for last point in noise, go point by point to left from minium on signal
		//as long as noise will be found
		
		int index = indexAtMinimumOfSignal;
		
		while(index> numberOfPointsTakenForAproximation)
		{		
			if( isPointFromRecoSignalInNoise( first20PointsMean, first20PointsDeviation, amplitudePoints[index] ) )
			{	
				return index;
			}
			index-=1;
		}
		return -666;
	}


double signalAnalysisTools::timeRise(std::pair<std::vector<double>, std::vector<double> >& data, double baseline, double amplitude)
{
    if(baseline == 666.666)
    {
        return -1.;
    }
    
    std::vector<double> amplitudePoints = data.second;
    std::vector<double> timePoints = data.first;
    int indexAtMinimumOfSignal = findIndexAtValue( min(amplitudePoints), amplitudePoints);
    double startTime = 0;
    double endTime = 0;
    int flag = 0;
   //Rise Time is Calculated between 20% to 80%  
    const double lowThr = 0.2 * amplitude;
    /*
    if( lowThr > -15.0 )
       return -1.;
     */  
    const double upThr = 0.8 * amplitude;
    
    startTime = calculateConstantThreshold(data, lowThr);
    endTime = calculateConstantThreshold(data, upThr);
    
    double time = endTime - startTime;
    return time;
}


double signalAnalysisTools::timeFall(std::pair<std::vector<double>, std::vector<double> >& data, double offset, double amplitude)
{
    if(offset == 666.666)
    {
        return -1.;
    }
    
    std::vector<double> amplitudePoints = data.second;
    std::vector<double> timePoints = data.first;
    int indexAtMinimumOfSignal = findIndexAtValue( min(amplitudePoints), amplitudePoints);
    double startTime = 0;
    double endTime = 0;
    int flag = 0;

    //Fall Time is calculated between 10% to 90%
    
    const double lowThr = 0.1 * amplitude;
    const double upThr = 0.9 * amplitude;
    
    startTime = calculateConstantThresholdFall(data, upThr);
    endTime = calculateConstantThresholdFall(data, lowThr);
    /*
    for(unsigned int index = indexAtMinimumOfSignal; index < amplitudePoints.size(); index++)
    {
        if( flag == 0 && (amplitudePoints[index] ) > 0.9 * amplitude )
        {
            startTime = timePoints[index];
            flag ++;
        }
        if( (amplitudePoints[index] ) > 0.1 * amplitude )
        {
            endTime = timePoints[index];
            break;
        }
    }*/
    
    double time = endTime - startTime;
    /*
    if(time < 0)
    {
        int size = (int)amplitudePoints.size();
        double t[size] = {};
        double a[size] = {};
        for(unsigned int index = 0; index < size; index++)
        {
            t[index] = timePoints[index];
            a[index] = amplitudePoints[index];
        }
        TCanvas *c = new TCanvas();
        TGraph* gr = new TGraph(size,t,a);
        gr->Draw("A*");
    }*/
    
    return time;
}



double signalAnalysisTools::calculateTimeAtThreshold(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold)
	{
		if(threshold > 0)
		{
			return calculateConstantThreshold(data, -1.0*threshold);
		}
		else
		{
	            return calculateConstantThreshold(data, threshold);
		}
		return 999;		
	}

double signalAnalysisTools::calculateConstantThresholdFall(std::pair<std::vector<double>, std::vector<double> >& data, const double threshold)
	{
		double timeAtThr = 999;
        std::vector<double> amplitudePoints = data.second;
        std::vector<double> timePoints = data.first;
		double thresholdPlusOffset = threshold;// + signal.getOffset();
	    double slope=1;
	    double intercept=0;
	    int indexAtMin = findIndexAtValue(min(amplitudePoints),amplitudePoints);
//             int justBeforeSignal = indexAtMin - 1000;
	    
	 //DEBUG STUFF
	/*
	    std::cout << "point number " << findIndexAtValue(min(amplitudePoints),amplitudePoints) << std::endl;
	    std::cout << "amplitude " << min(amplitudePoints) << std::endl;
            std::cout << "amplitude before signal: " << amplitudePoints[justBeforeSignal] << std::endl;
	*/  
	
// 	if( justBeforeSignal < 0 )
// 	  justBeforeSignal = 0;
	  for(unsigned int i= indexAtMin ; i < amplitudePoints.size(); i++){

			if(amplitudePoints[i+1]>thresholdPlusOffset&&amplitudePoints[i]<thresholdPlusOffset){
				slope= (amplitudePoints[i+1]-amplitudePoints[i])/(timePoints[i+1]-timePoints[i]);
				intercept=amplitudePoints[i]-(amplitudePoints[i+1]-amplitudePoints[i])/(timePoints[i+1]-timePoints[i])*timePoints[i];
		    timeAtThr=(thresholdPlusOffset-intercept)/slope;
		    break;
			}
	    }
	    return timeAtThr;
	}

