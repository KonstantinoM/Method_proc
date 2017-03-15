#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

#define M_PI 3.1415926535897932384626433832795

Sphere* InSphere(ifstream &f)
{
	Sphere *Sp;
	Sp = new Sphere;
	Sp->key = SPHERE;
	f >> Sp->r;
	return (Sphere*)Sp;
}

void OutSphere(Sphere* s, ofstream &f)
{
	f << "It's sphere: r = " << s->r;
}

float VolumeSphere (Sphere* s)
{
	return (float(4)/float(3)*M_PI*pow(s->r, 3.0));
}