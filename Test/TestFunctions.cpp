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

bool ComparePointerInContainer(cont *list1, cont *list2)
{
	if ((list1 == NULL)^(list2 == NULL))
		return false;
	if(list1->sh->key != list2->sh->key)
		return false;
	else
	{
		switch(list1->sh->key)
		{
		case SPHERE:
			{
				if (((Sphere*)list1->sh)->key != ((Sphere*)list2->sh)->key)
					return false;
				if (((Sphere*)list1->sh)->r != ((Sphere*)list2->sh)->r)
					return false;
				break;
			}
		case BOX:
			{
				if (((Box*)list1->sh)->key != ((Box*)list2->sh)->key)
					return false;
				if (((Box*)list1->sh)->a != ((Box*)list2->sh)->a)
					return false;
				if (((Box*)list1->sh)->b != ((Box*)list2->sh)->b)
					return false;
				if (((Box*)list1->sh)->c != ((Box*)list2->sh)->c)
					return false;
				break;
			}
		case TETRAHEDRON:
			{
				if (((Tetrahedron*)list1->sh)->key != ((Tetrahedron*)list2->sh)->key)
					return false;
				if (((Tetrahedron*)list1->sh)->a != ((Tetrahedron*)list2->sh)->a)
					return false;
				break;
			}
		default:
			{
				return false;
				break;
			}
		}
		if (list1->sh->p != list2->sh->p)
			return false;
		if (list1->sh->t != list2->sh->t)
			return false;
	}
	return true;
}

bool CompareContainer(cont *list1, cont *list2)
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

void ContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 6;
	list->sh = new Shape;
	((Tetrahedron*)list->sh)->key = TETRAHEDRON;
	((Tetrahedron*)list->sh)->a = 9;
	list->sh->key = TETRAHEDRON;
	list->sh->p = 98;
	list->sh->t = 354;
	list->next = list; 
	list->prev = list;

	cont *temp = new cont;
	temp->sh = new Shape;
	((Sphere*)temp->sh)->key = SPHERE;
	((Sphere*)temp->sh)->r = 67;
	temp->sh->key = SPHERE;
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Tetrahedron*)temp->sh)->key = TETRAHEDRON;
	((Tetrahedron*)temp->sh)->a = 3;
	temp->sh->key = TETRAHEDRON;
	temp->sh->p = 5;
	temp->sh->t = 34;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Box*)temp->sh)->key = BOX;
	((Box*)temp->sh)->a = 10;
	((Box*)temp->sh)->b = 8;
	((Box*)temp->sh)->c = 6;
	temp->sh->key = BOX;
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Box*)temp->sh)->key = BOX;
	((Box*)temp->sh)->a = 4;
	((Box*)temp->sh)->b = 12;
	((Box*)temp->sh)->c = 11;
	temp->sh->key = BOX;
	temp->sh->p = 123;
	temp->sh->t = 167;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Sphere*)temp->sh)->key = SPHERE;
	((Sphere*)temp->sh)->r = 6;
	temp->sh->key = SPHERE;
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
}


void SortContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 6;
	list->sh = new Shape;
	((Tetrahedron*)list->sh)->key = TETRAHEDRON;
	((Tetrahedron*)list->sh)->a = 3;
	list->sh->key = TETRAHEDRON;
	list->sh->p = 5;
	list->sh->t = 34;
	list->next = list; 
	list->prev = list;

	cont *temp = new cont;	
	temp->sh = new Shape;
	((Tetrahedron*)temp->sh)->key = TETRAHEDRON;
	((Tetrahedron*)temp->sh)->a = 9;
	temp->sh->key = TETRAHEDRON;
	temp->sh->p = 98;
	temp->sh->t = 354;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Box*)temp->sh)->key = BOX;
	((Box*)temp->sh)->a = 10;
	((Box*)temp->sh)->b = 8;
	((Box*)temp->sh)->c = 6;
	temp->sh->key = BOX;
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Box*)temp->sh)->key = BOX;
	((Box*)temp->sh)->a = 4;
	((Box*)temp->sh)->b = 12;
	((Box*)temp->sh)->c = 11;
	temp->sh->key = BOX;
	temp->sh->p = 123;
	temp->sh->t = 167;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Sphere*)temp->sh)->key = SPHERE;
	((Sphere*)temp->sh)->r = 6;
	temp->sh->key = SPHERE;
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Sphere*)temp->sh)->key = SPHERE;
	((Sphere*)temp->sh)->r = 67;
	temp->sh->key = SPHERE;
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
}

void OneSphereInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Shape;
	((Sphere*)list->sh)->key = SPHERE;
	((Sphere*)list->sh)->r = 9;
	list->sh->key = SPHERE;
	list->sh->p = 98;
	list->sh->t = 354;
	list->next = list; 
	list->prev = list;
}

void OneBoxInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Shape;
	((Box*)list->sh)->key = BOX;
	((Box*)list->sh)->a = 9;
	((Box*)list->sh)->b = 13;
	((Box*)list->sh)->c = 34;
	list->sh->key = BOX;
	list->sh->p = 58;
	list->sh->t = 134;
	list->next = list; 
	list->prev = list;
}

void OneTetrahedronInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Shape;
	((Tetrahedron*)list->sh)->key = TETRAHEDRON;
	((Tetrahedron*)list->sh)->a = 9;
	list->sh->key = TETRAHEDRON;
	list->sh->p = 58;
	list->sh->t = 134;
	list->next = list; 
	list->prev = list;
}