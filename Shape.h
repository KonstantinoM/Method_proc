#include "Sphere.h"
#include "Box.h"
#include "Tetrahedron.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Shape
{
	type key;
	float p;
	int t;
};

Shape* In(ifstream &f);
void Out(Shape* s,ofstream &f);
float Volume (Shape* s);
bool Compare(Shape *f, Shape *s);