#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

#define PI 3.1415926535897932384626433832795

Sphere* InSphere(ifstream &file)
{
	CheckInputFile(file);
	Sphere *sphere;
	sphere = new Sphere;
	sphere->key = SPHERE;
	file >> sphere->r;
	CheckInputValue(file);
	CheckNonnegativeness(sphere->r);
	return (Sphere*)sphere;
}

void OutSphere(Sphere* sphere, ofstream &file)
{
	CheckOutputFile(file);
	file << "It's sphere: r = " << sphere->r;
}

float VolumeSphere (Sphere* sphere)
{
	return (float(4)/float(3)*PI*pow(sphere->r, 3.0));
}