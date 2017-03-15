#include "Enu.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Sphere
{
	type key;
	float p;
	int t;
	int r;
};

Sphere* InSphere(ifstream &f);
void OutSphere(Sphere* s, ofstream &f);
float VolumeSphere (Sphere* s);