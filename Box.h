#include "Enu.h"
#include <iostream>
#include <fstream>
using namespace std;
struct Box
{
	type key;
	float p;
	int t;
	int a;
	int b;
	int c;
};

Box* InBox(ifstream &f);
void OutBox(Box* bo, ofstream &f);
float VolumeBox (Box* bo);