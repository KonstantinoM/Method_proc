#include "Enu.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Tetrahedron
{
	type key;
	float density;
	int temperature;
	int a;
};

Tetrahedron* InTetrahedron(ifstream &file);
void OutTetrahedron(Tetrahedron* tetrahedron, ofstream &file);
float VolumeTetrahedron (Tetrahedron* tile);