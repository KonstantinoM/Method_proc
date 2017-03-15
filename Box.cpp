#include "stdafx.h"
#include "Box.h"
#include <iostream>
#include <fstream>
using namespace std;

Box* InBox(ifstream &f)
{
	Box *B;
	B = new Box;
	B->key = BOX;
	f >> B->a;
	f >> B->b;
	f >> B->c;
	return (Box*)B;
}

void OutBox(Box* bo, ofstream &f)
{
	f << "It's box: a = " << bo->a << ", b = " << bo->b << ", c = " << bo->c;
}

float VolumeBox (Box* bo)
{
	return (bo->a*bo->b*bo->c);
}