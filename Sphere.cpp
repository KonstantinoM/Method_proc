#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
using namespace std;

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