#include "Enu.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Sphere
{
	type key;
	float density;
	int temperature;
	int r;
};

Sphere* InSphere(ifstream &file);
void OutSphere(Sphere* sphere, ofstream &file);
float VolumeSphere (Sphere* sphere);