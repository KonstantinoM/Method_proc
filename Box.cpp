#include "stdafx.h"
#include "Box.h"
#include <iostream>
#include <fstream>
using namespace std;

Box* InBox(ifstream &file)
{
	CheckInputFile(file);
	Box *box;
	box = new Box;
	box->key = BOX;
	file >> box->a;
	CheckInputValue(file);
	CheckNonnegativeness(box->a);
	file >> box->b;
	CheckInputValue(file);
	CheckNonnegativeness(box->b);
	file >> box->c;
	CheckInputValue(file);
	CheckNonnegativeness(box->c);
	return (Box*)box;
}

void OutBox(Box* box, ofstream &file)
{
	CheckOutputFile(file);
	file << "It's box: a = " << box->a << ", b = " << box->b << ", c = " << box->c;
}

float VolumeBox (Box* box)
{
	return (box->a*box->b*box->c);
}