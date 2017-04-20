#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;	

void CheckInputFile(ifstream &file)
{
	if(!file)
	{
		cout << "Error. Can't open input file." << endl;
		system("pause");
		exit(1);
	}
}

void CheckInputValue(ifstream &file)
{
	if(file.fail())
	{
		cout << "Error. Incorrect values. There are strange symbols in the input file or there is int or float overflow." << endl;
		system("pause");
		exit(1);
	}
}

void CheckNonnegativeness(float value)
{
	if(value < 0)
	{
		cout << "Error. Incorrect values. There are negative values." << endl;
		system("pause");
		exit(1);
	}
}

void CheckOutputFile(ofstream &file)
{
 	if(!file)
 	{
 		cout << "Error. Can't open output file." << endl;
		system("pause");
		exit(1);
	}
}