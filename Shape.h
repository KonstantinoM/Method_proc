#include "Sphere.h"
#include "Box.h"
#include "Tetrahedron.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Shape
{
	type key;
	float density;
	int temperature;
};

Shape* In(ifstream &file);
void Out(Shape* shape,ofstream &file);
float Volume (Shape* shape);
bool Compare(Shape* shape1, Shape*shape2);