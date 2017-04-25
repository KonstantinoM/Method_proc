#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

struct Container
{
	int n;
	Shape* shape;
	Container *next;
	Container *prev;
};

void Init(Container* &container);
void InContainer(Container* &container, ifstream &file);
void OutContainer(Container* container, ofstream &file);
void Clear(Container* &container);
void Sort(Container* &container);
void OutContainerOnlySphere(Container* container, ofstream &file);
void MultiMethod(Container* container, ofstream &file);