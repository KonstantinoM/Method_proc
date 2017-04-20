#include "stdafx.h"
#include <string>
#include "iostream"
#include <fstream>
#include "TestFunctions.h"
using namespace std;

bool CompareFiles(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	int i = 0;
	while ((!f1.eof())||(!f2.eof())) 
	{ 
		getline(f1, s1); 
		getline(f2, s2); 
		if (s1 != s2)
		{
			cout << "String " << i+1 << "\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
		i += 1;
	}
	return true;
}

bool ComparePointerInContainer(Container *list1, Container *list2)
{
	if ((list1 == NULL)^(list2 == NULL))
		return false;
	if(list1->shape->key != list2->shape->key)
		return false;
	else
	{
		switch(list1->shape->key)
		{
		case SPHERE:
			{
				if (((Sphere*)list1->shape)->key != ((Sphere*)list2->shape)->key)
					return false;
				if (((Sphere*)list1->shape)->r != ((Sphere*)list2->shape)->r)
					return false;
				break;
			}
		case BOX:
			{
				if (((Box*)list1->shape)->key != ((Box*)list2->shape)->key)
					return false;
				if (((Box*)list1->shape)->a != ((Box*)list2->shape)->a)
					return false;
				if (((Box*)list1->shape)->b != ((Box*)list2->shape)->b)
					return false;
				if (((Box*)list1->shape)->c != ((Box*)list2->shape)->c)
					return false;
				break;
			}
		case TETRAHEDRON:
			{
				if (((Tetrahedron*)list1->shape)->key != ((Tetrahedron*)list2->shape)->key)
					return false;
				if (((Tetrahedron*)list1->shape)->a != ((Tetrahedron*)list2->shape)->a)
					return false;
				break;
			}
		default:
			{
				return false;
				break;
			}
		}
		if (list1->shape->density != list2->shape->density)
			return false;
		if (list1->shape->temperature != list2->shape->temperature)
			return false;
	}
	return true;
}

bool CompareContainer(Container *list1, Container *list2)
{
	if (list1->n != list2->n)
		return false;
	else
	{
		int n = list1->n;
		for (int i = 0; i < n; i++)
		{
			if (!ComparePointerInContainer(list1, list2))
				return false;
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	return true;
}

void ContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 6;
	list->shape = new Shape;
	((Tetrahedron*)list->shape)->key = TETRAHEDRON;
	((Tetrahedron*)list->shape)->a = 9;
	list->shape->key = TETRAHEDRON;
	list->shape->density = 98;
	list->shape->temperature = 354;
	list->next = list; 
	list->prev = list;

	Container *temp = new Container;
	temp->shape = new Shape;
	((Sphere*)temp->shape)->key = SPHERE;
	((Sphere*)temp->shape)->r = 67;
	temp->shape->key = SPHERE;
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Tetrahedron*)temp->shape)->key = TETRAHEDRON;
	((Tetrahedron*)temp->shape)->a = 3;
	temp->shape->key = TETRAHEDRON;
	temp->shape->density = 5;
	temp->shape->temperature = 34;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 10;
	((Box*)temp->shape)->b = 8;
	((Box*)temp->shape)->c = 6;
	temp->shape->key = BOX;
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 4;
	((Box*)temp->shape)->b = 12;
	((Box*)temp->shape)->c = 11;
	temp->shape->key = BOX;
	temp->shape->density = 123;
	temp->shape->temperature = 167;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Sphere*)temp->shape)->key = SPHERE;
	((Sphere*)temp->shape)->r = 6;
	temp->shape->key = SPHERE;
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
}


void SortContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 6;
	list->shape = new Shape;
	((Tetrahedron*)list->shape)->key = TETRAHEDRON;
	((Tetrahedron*)list->shape)->a = 3;
	list->shape->key = TETRAHEDRON;
	list->shape->density = 5;
	list->shape->temperature = 34;
	list->next = list; 
	list->prev = list;

	Container *temp = new Container;	
	temp->shape = new Shape;
	((Tetrahedron*)temp->shape)->key = TETRAHEDRON;
	((Tetrahedron*)temp->shape)->a = 9;
	temp->shape->key = TETRAHEDRON;
	temp->shape->density = 98;
	temp->shape->temperature = 354;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 10;
	((Box*)temp->shape)->b = 8;
	((Box*)temp->shape)->c = 6;
	temp->shape->key = BOX;
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 4;
	((Box*)temp->shape)->b = 12;
	((Box*)temp->shape)->c = 11;
	temp->shape->key = BOX;
	temp->shape->density = 123;
	temp->shape->temperature = 167;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Sphere*)temp->shape)->key = SPHERE;
	((Sphere*)temp->shape)->r = 6;
	temp->shape->key = SPHERE;
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Sphere*)temp->shape)->key = SPHERE;
	((Sphere*)temp->shape)->r = 67;
	temp->shape->key = SPHERE;
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
}

void OneSphereInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Shape;
	((Sphere*)list->shape)->key = SPHERE;
	((Sphere*)list->shape)->r = 9;
	list->shape->key = SPHERE;
	list->shape->density = 98;
	list->shape->temperature = 354;
	list->next = list; 
	list->prev = list;
}

void OneBoxInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Shape;
	((Box*)list->shape)->key = BOX;
	((Box*)list->shape)->a = 9;
	((Box*)list->shape)->b = 13;
	((Box*)list->shape)->c = 34;
	list->shape->key = BOX;
	list->shape->density = 58;
	list->shape->temperature = 134;
	list->next = list; 
	list->prev = list;
}

void OneTetrahedronInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Shape;
	((Tetrahedron*)list->shape)->key = TETRAHEDRON;
	((Tetrahedron*)list->shape)->a = 9;
	list->shape->key = TETRAHEDRON;
	list->shape->density = 58;
	list->shape->temperature = 134;
	list->next = list; 
	list->prev = list;
}