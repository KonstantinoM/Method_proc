#include "stdafx.h"
#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

Shape* In(ifstream &f)
{
	Shape *s;
	int key = 0;
	f >> key;
	switch(key)
	{
		case 0: //Это сфера
			{
				s = (Shape*)InSphere(f);
				s->key = SPHERE;
				break;
			}
		case 1: //Это параллелепипед
			{
				s = (Shape*)InBox(f);
				s->key = BOX;
				break;
			}
		default:
			break;
	}
	f >> s->p;
	f >> s->t;
	return (Shape*)s;
}

void Out(Shape* s,ofstream &f)
{
	switch(s->key)
	{
		case SPHERE:
			{
				OutSphere((Sphere*)s, f);
				break;
			}
		case BOX:
			{
				OutBox((Box*)s, f);
				break;
			}
		default:
			break;
	}
	f << ", p = " << s->p << ", t = " << s->t<< endl;
}