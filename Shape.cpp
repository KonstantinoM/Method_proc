#include "stdafx.h"
#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

Shape* In(ifstream &file)
{
	CheckInputFile(file);
	if(file.eof())
	{
		cout << "Error. Too many shapes is specified." << endl;
		system("pause");
		exit(1);
	}
	Shape *shape;
	int key = 0;
	file >> key;
	CheckInputValue(file);
	CheckNonnegativeness(key);
	if (key > 2)
	{
		cout << "Error. Incorrect values. The key can take the values 0, 1, 2." << endl;
		system("pause");
		exit(1);
	}
	switch(key)
	{
		case 0: //Это сфера
			{
				shape = (Shape*)InSphere(file);
				shape->key = SPHERE;
				break;
			}
		case 1: //Это параллелепипед
			{
				shape = (Shape*)InBox(file);
				shape->key = BOX;
				break;
			}
		case 2: //Это тетраэдр
			{
				shape = (Shape*)InTetrahedron(file);
				shape->key = TETRAHEDRON;
				break;
			}
		default:
			break;
	}
	file >> shape->density;
	CheckInputValue(file);
	CheckNonnegativeness(shape->density);
	file >> shape->temperature;
	CheckInputValue(file);
	CheckNonnegativeness(shape->temperature);
	return (Shape*)shape;
}

void Out(Shape* shape,ofstream &file)
{
	CheckOutputFile(file);
	switch(shape->key)
	{
		case SPHERE:
			{
				OutSphere((Sphere*)shape, file);
				break;
			}
		case BOX:
			{
				OutBox((Box*)shape, file);
				break;
			}
		case TETRAHEDRON:
			{
				OutTetrahedron((Tetrahedron*)shape, file);
				break;
			}
		default:
			break;
	}
	file << ", p = " << shape->density << ", t = " << shape->temperature;//<< endl;
}

float Volume (Shape* shape)
{
	switch(shape->key)
	{
		case SPHERE:
			{
				return VolumeSphere((Sphere*)shape);
				break;
			}
		case BOX:
			{
				return VolumeBox((Box*)shape);
				break;
			}
		case TETRAHEDRON:
			{
				return VolumeTetrahedron((Tetrahedron*)shape);
				break;
			}
		default:
			break;
	}
}