#include "Enu.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
using namespace std;
struct Box
{
	type key;
	float density;
	int temperature;
	int a;
	int b;
	int c;
};

Box* InBox(ifstream &file);
void OutBox(Box* box, ofstream &file);
float VolumeBox (Box* box);