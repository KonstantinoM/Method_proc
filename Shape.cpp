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
		case 0: //��� �����
			{
				s = (Shape*)InSphere(f);
				s->key = SPHERE;
				f >> s->p;
				break;
			}
		case 1: //��� ��������������
			{
				s = (Shape*)InBox(f);
				s->key = BOX;
				f >> s->p;
				break;
			}
		default:
			break;
	}
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
	f << ", p = " << s->p;
}

float Volume (Shape* s)
{
	switch(s->key)
	{
		case SPHERE:
			{
				return VolumeSphere((Sphere*)s);
				break;
			}
		case BOX:
			{
				return VolumeBox((Box*)s);
				break;
			}
		default:
			break;
	}
}