// met1proc.cpp: определяет точку входа для консольного приложения.
// Константинова Мария, КИ13-01

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "windows.h"
#include "Container.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc !=3) 
	{
		cout << "Error. Incorrect command line! Waited: command in_file out_file" << endl;
		return 0;
	}
	ifstream inputFile(argv[1]);
	CheckInputFile(inputFile);

	inputFile.seekg (0, std::ios::end); 
	int fileSize = inputFile.tellg(); 
	inputFile.seekg (0, std::ios::beg); 
	if (fileSize == 0) 
	{ 
			cout << "Error. Input file is empty." << endl;
			system("pause");
			return 0;
	}

	Container *container = NULL;
	Init(container);
	InContainer(container, inputFile);

	ofstream outputFile(argv[2]);
	CheckOutputFile(outputFile);
	OutContainer(container, outputFile);
	outputFile << "\n\n";
	OutContainerOnlySphere(container, outputFile);
	MultiMethod(container, outputFile);
	Clear(container);
	return 0;
}

