// Bianca Hernandez
// Coleman Johnston
// Lesley Amezcua
// Created: 10/30/15
// Summary: Determining whether or not Maria's voice was found in the voice 
//recording 
// The values that match most closely: Standard Deviation 
// The values that are most different: Number of zero crossings
// Based on our results in the number of zero crossings we conclude that
//the sound recordings are from different people.
//**********************************************************************
#include <iostream>//cout
#include <fstream>//file in/out
#include <vector>//vectors
#include <cstdlib>
#include <cmath>//fabs(),pow()
#include <iomanip>//setw()

using namespace std;

//***********************************************************************
double mean(vector<double> v, int n);
//Summary: Calculates the average.
//Precondition: Takes in a vector of type double and the number of values
//inside the vector.
//Postcondition: Returns the mean (or average) of all the values in the 
//vector or from v[0] to v[n]. 
//
//***********************************************************************
double variance(vector<double> v, int n, double means);
//Summary: Calculates the variance.
//Precondition: Takes in a vector of doubles, the number of elements in
//the vector, and the mean of all the values in the vector.
//Postcondition: Returns the variance of all the values in the vector.
//***********************************************************************
double stdDev(double var);
//Summary: Calculates the standard deviation.
//Precondition: Takes in the variance.
//Postcondition: Returns the standard deviation based on the variance.
//
//***********************************************************************
double avgMagnitude(vector<double> v, int n);
//Summary: Calculates the average magnitude.
//Precondition: Takes in a vector filled with doubles, and the number of 
//elements in the vector.
//Postcondition: Returns the average magnitude of the values in the vector
//from v[0] to v[n].
//
//***********************************************************************
double avgPower(vector<double> v, int n);
//Summary: Calculates the average power.
//Precondition: Takes in a vector of doubles and the number of elements in
//the vector.
//Postcondition: Returns the average power of all the values in the vector.
//
//***********************************************************************
int zeroCrossings(vector<double> v, int n);
//Summary: Finds the number of zero crossings.
//Precondition: Takes in a vector of doubles, and the number of elements
//in the vector.
//Postcondition: Returns the number of times the values in the vector 
//cross zero (go from <0 to >0 or vice versa).
//
//***********************************************************************
double perDif(double a, double b);
//Summary: Calculates the percent difference 
//
//***********************************************************************

int main()
{
	ifstream fin;
	ifstream fin1;
	ofstream fout;
	double signal, voice1Avg, voice2Avg, voice1Var, voice2Var, voice1SD, voice2SD, voice1Mag, voice2Mag, voice1Pow, voice2Pow, voice1Zero, voice2Zero;
	
	fin.open("two_a.txt");
	fin1.open("two_b.txt");
	fout.open("comparison.txt");
	
	if(fin.fail() || fin1.fail() || fout.fail())
	{
		cout << "Error Opening file. " << endl;
		exit(1);
	}
	
	vector<double> voice1;
	vector<double> voice2;
	
	while(fin >> signal)
	{
		voice1.push_back(signal);
	}
	while(fin1 >> signal)
	{
		voice2.push_back(signal);
	}
	fout <<"Team Members: "<< setw(6)<<" Bianca Hernandez    Coleman Johnston   Lesley Amezcua" << endl << endl;
	voice1Avg = mean(voice1, voice1.size());
	voice2Avg = mean(voice2, voice2.size());
	fout << fixed << setprecision(5) << left << setw(12);
	fout << "\t\t\t\ttwo_a.txt\ttwo_b.txt\t% Difference" << endl;
	fout << "Mean:\t\t\t" << voice1Avg << "\t\t" << voice2Avg << "\t\t" << perDif(voice1Avg, voice2Avg) << endl;
	
	voice1Var = variance(voice1, voice1.size(), voice1Avg);
	voice2Var = variance(voice2, voice2.size(), voice2Avg);
	fout << "Variance: \t\t" << voice1Var << "\t\t"<< voice2Var << "\t\t"<< perDif(voice1Var, voice2Var) << endl;
	
	voice1SD = stdDev(voice1Var);
	voice2SD = stdDev(voice2Var);
	fout << "StdDeviation: \t" << voice1SD << "\t\t"<< voice2SD << "\t\t"<< perDif(voice1SD, voice2SD) << endl;
	
	voice1Mag = avgMagnitude(voice1, voice1.size());
	voice2Mag = avgMagnitude(voice2, voice2.size());
	fout << "Magnitude: \t\t" << voice1Mag << "\t\t" << voice2Mag << "\t\t" << perDif(voice1Mag, voice2Mag) << endl;
	
	voice1Pow = avgPower(voice1, voice1.size());
	voice2Pow = avgPower(voice2, voice2.size());
	fout << "Power: \t\t\t" << voice1Pow << "\t\t" << voice2Pow << "\t\t" << perDif(voice1Pow, voice2Pow) << endl;
	
	voice1Zero = zeroCrossings(voice1, voice1.size());
	voice2Zero = zeroCrossings(voice2, voice2.size());
	fout << "Crossings: \t\t" << voice1Zero << "\t" << voice2Zero << "\t" << perDif(voice1Zero, voice2Zero) << endl;
	
	fin.close();
	fin1.close();
	fout.close();
	return 0;
} // End of Main

//*************************************************************
double mean(vector<double> v, int n)
{
	double total = 0;//sum of all elements in the vector v.
    double avg;//the average or mean 
    for (int i = 0; i < n; i++)
    {
        total += v[i];
    }
    avg = total / n;
	return avg;//return the average or mean
}// End of means

//*************************************************************
double variance(vector<double> v, int n , double means)
{
	double sum = 0.0;
	for(int i = 0; i < n; i++)
	{
	  sum += pow( (v[i] - means) , 2 );//(v[i] - mean)^2  
	}
	return (sum / n);//take the average and return the result.
}// End of Variance

//*************************************************************
double stdDev(double var)
{
	return sqrt(var);
}// End of StdDev

//*************************************************************
double avgMagnitude(vector<double> v, int n)
{
	double avgMag = 0.0;
	for(int i = 0; i < n; i++)
	{
	    avgMag += fabs(v[i]);//sum up the absolute values
	}
	avgMag = avgMag / n;//find the average 
	return avgMag;
} // End of avgMagnitude

//*************************************************************
double avgPower(vector<double> v, int n)
{
	double avgPow = 0.0; 
	for(int i = 0; i < n; i++)
	{
	    avgPow += pow(v[i],2);//sum up the values squared. 
	}
	avgPow = avgPow / n;
	return avgPow;
} // End of avgPower

//*************************************************************
int zeroCrossings(vector<double> v, int n)
{
	int zeroCross = 0;
	bool ispos = false;//boolean for the current value
	bool waspos = false;//boolean for the previous value
	if (v[0] > 0)//initialize waspos so the loop can start 
	{
		waspos = true;
	}
	for(int i = 1; i < n; i++)
	{
		if(v[i] > 0)
		{
			ispos = true;//if current value is positive
		}
		if(v[i] < 0)
		{
			ispos = false;//if the current value is negative 
		}
		if (ispos != waspos)
		{
			zeroCross++;//if crossed zero
		}
		waspos = ispos;//make the current value the past value
	}
	return zeroCross;
}// End of zeroCrossings

//***********************************************************
double perDif(double a, double b)
{
	if(a == b)
	{
		return 0;
	}
	double per;
	per=(fabs(a-b)/((a+b) /2))* 100;
	return per;
}
