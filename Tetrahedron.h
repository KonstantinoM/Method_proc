#include "Enu.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Tetrahedron
{
	type key;
	float p;
	int t;
	int a;
};

Tetrahedron* InTetrahedron(ifstream &f);
void OutTetrahedron(Tetrahedron* t, ofstream &f);