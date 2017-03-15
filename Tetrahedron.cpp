#include "stdafx.h"
#include "Tetrahedron.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

Tetrahedron* InTetrahedron(ifstream &f)
{
	Tetrahedron *T;
	T = new Tetrahedron;
	T->key = TETRAHEDRON;
	f >> T->a;
	return (Tetrahedron*)T;
}

void OutTetrahedron(Tetrahedron* t, ofstream &f)
{
	f << "It's tetrahedron: a = " << t->a;
}

float VolumeTetrahedron (Tetrahedron* t)
{
	return ((sqrt(2.0))*pow(t->a,3.0)/12);
}