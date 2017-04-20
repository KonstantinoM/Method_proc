#include "stdafx.h"
#include "Tetrahedron.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

Tetrahedron* InTetrahedron(ifstream &file)
{
	CheckInputFile(file);
	Tetrahedron *tetrahedron;
	tetrahedron = new Tetrahedron;
	tetrahedron->key = TETRAHEDRON;
	file >> tetrahedron->a;
	CheckInputValue(file);
	CheckNonnegativeness(tetrahedron->a);
	return (Tetrahedron*)tetrahedron;
}

void OutTetrahedron(Tetrahedron* tetrahedron, ofstream &file)
{
	CheckOutputFile(file);
	file<< "It's tetrahedron: a = " << tetrahedron->a;
}

float VolumeTetrahedron (Tetrahedron* tetrahedron)
{
	return ((sqrt(2.0))*pow(tetrahedron->a,3.0)/12);
}