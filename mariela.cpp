// Bianca Hernandez
// Coleman Johnston
// Lesley Amezcua
// Created: 10/30/15
// Summary: 
//
//**********************************************************************
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;
double mean(vector<double> v, int n);
double variance(vector<double> v, int n, double means);
double stdDev(double var);
double avgMagnitude(vector<double> v, int n);
double avgPower(vector<double> v, int n);
double zeroCrossings(vector<double> v, int n);

int main()
{
	ifstream fin;
	ifstream fin1;
	ofstream fout;
	double signal, voice1Avg, voice2Avg, voice1Var, voice2Var, voice1SD, voice2SD, voice1Mag, voice2Mag, voice1Pow, voice2Pow;
	
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
	cout << voice1.size() << endl;
	cout << voice2.size() << endl;
	
	voice1Avg = mean(voice1, voice1.size());
	voice2Avg = mean(voice2, voice2.size());
	voice1Var = variance(voice1, voice1.size(), voice1Avg);
	voice2Var = variance(voice2, voice2.size(), voice2Avg);
	voice1SD = stdDev(voice1Var);
	voice2SD = stdDev(voice2Var);
	
	fin.close();
	fin1.close();
	fout.close();
	return 0;
} // End of Main

//*************************************************************
double mean(vector<double> v, int n)
{
	return 3.4;
}// End of means

//*************************************************************
double variance(vector<double> v, int n , double means)
{
	return 3.4;
}// End of Variance

//*************************************************************
double stdDev(double var)
{
	return 3.4;
}// End of StdDev

//*************************************************************
double avgMagnitude(vector<double> v, int n)
{
	return 3.4;
} // End of avgMagnitude

//*************************************************************
double avgPower(vector<double> v, int n)
{
	return 3.4;
} // End of avgPower

//*************************************************************
double zeroCrossings(vector<double> v, int n)
{
	return 3.4;
}// End of zeroCrossings
