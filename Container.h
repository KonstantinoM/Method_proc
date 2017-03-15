#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

struct cont
{
	int n;
	Shape* sh;
	cont *next;
	cont *prev;
};

void Init(cont* &l);
void Incont(cont* &l, ifstream &f);
void Outcont(cont* l, ofstream &f);
void Clear(cont* &l);