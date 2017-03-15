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

void OutcontOnlySphere(cont* l, ofstream &f)
{
	int n = l->n;
	f << "Only spheres:" <<  endl;
	for (int i = 0; i < n; i++)
	{
		f << i+1 << ": ";
		if (l->sh->key == SPHERE)
			Out(l->sh, f);
		else
			f << endl;
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