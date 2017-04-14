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
	Sort(l);
	for (int i = 0; i < n; i++)
	{
		f << i+1 << ": ";
		Out(l->sh, f);
		f << ", V = " << Volume(l->sh) << endl;
		l = l->next;
	}
}

void OutcontOnlySphere(cont* l, ofstream &f)
{
	int n = l->n;
	Sort(l);
	f << "Only spheres:" <<  endl;
	for (int i = 0; i < n; i++)
	{
		f << i+1 << ": ";
		if (l->sh->key == SPHERE)
		{
			Out(l->sh, f);
			f << ", V = " << Volume(l->sh) << endl;
			//f << endl;
		}
		else
			f << endl;
		l = l->next;
	}
}

void Clear(cont* &l)
{
	while (l->n > 1) 
	{
		/*
		cont* temp = l->next;
		temp = l->next;
		...
		delete l->sh;
		delete l;
		...
		*/
		cont* temp = new cont;
		temp = l->next;
		temp->prev = l->prev;
		l->prev->next = temp;
		delete l; 
		l = temp;
    }
	Init(l);
}

void Sort(cont* &l) 
{
	int n = l->n;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(Compare(l->sh, l->next->sh))
			{
				//cout << ", V = " << Volume(l->sh) << endl;
				//cout << ", V = " << Volume(l->next->sh) << endl;
				//cout << "\n";
				cont *temp = l->next->next;
				cont *prev = l->prev;
				cont *next = l->next;
				l->prev->next = next;
				l->next->prev = prev;
				l->next->next->prev = l;
				l->next->next = l;
				l->prev = next;
				l->next = temp;
			}
			else
				l = l->next;
			/*
			if(Compare(l->sh, l->next->sh))
			{
				swap(l->sh,l->next->sh); //#include <algorithm>
			}
			else ...
			*/
		}
		for (int j = 0; j <= i; j++)
			l = l->next;
	}
}
