#include "stdafx.h"
#include "Container.h"
#include <iostream>
#include <fstream>
using namespace std;

void Init(cont* &l)
{
	l= new cont;
	l->sh = NULL;
	l->n = 0;
	l->next = l; 
	l->prev = l;
}

void Incont(cont* &l, ifstream &f)
{
	f >> l->n; 
	l->sh = In(f);
	for (int i = 0; i < l->n-1; i++)
	{
		cont *temp = new cont;
		temp->sh = In(f);
		temp->n = l->n-1-i;
		temp->next = l;
		temp->prev = l->prev;
		l->prev->next = temp;
		l->prev = temp;
	}
}

void Outcont(cont* l, ofstream &f)
{
	int n = l->n;
	f << "Total number = " << n <<  endl;
	for (int i = 0; i < n; i++)
	{
		Out(l->sh, f);
		l = l->next;
	}
}

void Clear(cont* &l)
{
	while (l->n != 1) 
	{
		cont* temp = new cont;
		temp = l->next;
		temp->prev = l->prev;
		l->prev->next = temp;
		delete l; 
		l = temp;
    }
	Init(l);
}

void MultiMethod(cont* l, ofstream &f)
{
	f << endl << "Multimethod:" << endl;
	cont *temp1 = l;
	cont *temp2 = l;
	while(temp1->next != l)
	{
		temp2 = temp1->next;
		while (temp2 != l) 
		{
			switch(temp1->sh->key)
			{
			case SPHERE:
				{
					switch(temp2->sh->key)
					{
					case SPHERE:
						{
							f << "Sphere and Sphere:" << endl;
							break;
						}
					case BOX:
						{
							f << "Sphere and Box:" << endl;
							break;
						}
					default:
						{
							f << "Unknown type" << endl;
							break;
						}
					}
					break;
				}
			case BOX:
				{
					switch(temp2->sh->key)
					{
					case SPHERE:
						{
							f << "Box and Sphere:" << endl;
							break;
						}
					case BOX:
						{
							f << "Box and Box:" << endl;
							break;
						}
					default:
						{
							f << "Unknown type" << endl;
							break;
						}
					}
					break;
				}
			default:
				{	
					f << "Unknown type" << endl;
					break;
				}
			}
			Out(temp1->sh, f);
			Out(temp2->sh, f);
			f << endl;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}

}