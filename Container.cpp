#include "stdafx.h"
#include "Container.h"
#include <iostream>
#include <fstream>
using namespace std;

void Init(Container* &container)
{
	container = new Container;
	container->shape = NULL;
	container->n = 0;
	container->next = container; 
	container->prev = container;
}

void InContainer(Container* &container, ifstream &file)
{
	CheckInputFile(file);
	file >> container->n;
	CheckInputValue(file);
	CheckNonnegativeness(container->n);
	container->shape = In(file);
	for (int i = 0; i < container->n-1; i++)
	{
		Container *temp = new Container;
		temp->shape = In(file);
		temp->n = container->n-1-i;
		temp->next = container;
		temp->prev = container->prev;
		container->prev->next = temp;
		container->prev = temp;
	}
	if(!file.eof())
	{
		cout << "Error. There's some odd data" << endl;
		system("pause");
		exit(1);
	}
}

void OutContainer(Container* container, ofstream &file)
{
	CheckOutputFile(file);
	int n = container->n;
	file << "Total number = " << n <<  endl;
	Sort(container);
	for (int i = 0; i < n; i++)
	{
		file << i+1 << ": ";
		Out(container->shape, file);
		file << ", V = " << Volume(container->shape) << endl;
		container = container->next;
	}
}

void OutContainerOnlySphere(Container* container, ofstream &file)
{
	CheckOutputFile(file);
	int n = container->n;
	Sort(container);
	file << "Only spheres:" <<  endl;
	for (int i = 0; i < n; i++)
	{
		file << i+1 << ": ";
		if (container->shape->key == SPHERE)
		{
			Out(container->shape, file);
			file << ", V = " << Volume(container->shape) << endl;
			//f << endl;
		}
		else
			file << endl;
		container = container->next;
	}
}

void Clear(Container* &container)
{
	while (container->n > 1) 
	{
		Container* temp = container->next;
		temp->prev = container->prev;
		container->prev->next = temp;
		delete container; 
		container = temp;
    }
	Init(container);
}

void Sort(Container* &container) 
{
	int n = container->n;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if(Compare(container->shape, container->next->shape))
			{
				//cout << ", V = " << Volume(l->sh) << endl;
				//cout << ", V = " << Volume(l->next->sh) << endl;
				//cout << "\n";

				//Container *temp = l->next->next;
				//Container *prev = l->prev;
				//Container *next = l->next;
				//l->prev->next = next;
				//l->next->prev = prev;
				//l->next->next->prev = l;
				//l->next->next = l;
				//l->prev = next;
				//l->next = temp;
				Container *temp = new Container;
				temp->shape = container->shape;
				container->shape = container->next->shape;
				container->next->shape = temp->shape;
			}
			//else
				container = container->next;
		}
		for (int j = 0; j <= i; j++)
			container = container->next;
	}
}

void MultiMethod(Container* container, ofstream &file)
{
	file << endl << "Multimethod:" << endl;
	Container *temp1 = container;
	Container *temp2 = container;
	while(temp1->next != container)
	{
		temp2 = temp1->next;
		while (temp2 != container) 
		{
			switch(temp1->shape->key)
			{
			case SPHERE:
				{
					switch(temp2->shape->key)
					{
					case SPHERE:
						{
							file << "Sphere and Sphere:" << endl;
							break;
						}
					case BOX:
						{
							file << "Sphere and Box:" << endl;
							break;
						}
					case TETRAHEDRON:
						{
							file << "Sphere and Tetrahedron:" << endl;
							break;
						}
					default:
						{
							file << "Unknown type" << endl;
							break;
						}
					}
					break;
				}
			case BOX:
				{
					switch(temp2->shape->key)
					{
					case SPHERE:
						{
							file << "Box and Sphere:" << endl;
							break;
						}
					case BOX:
						{
							file << "Box and Box:" << endl;
							break;
						}
					case TETRAHEDRON:
						{
							file << "Box and Tetrahedron:" << endl;
							break;
						}
					default:
						{
							file << "Unknown type" << endl;
							break;
						}
					}
					break;
				}
			case TETRAHEDRON:
				{
					switch(temp2->shape->key)
					{
					case SPHERE:
						{
							file << "Tetrahedron and Sphere:" << endl;
							break;
						}
					case BOX:
						{
							file << "Tetrahedron and Box:" << endl;
							break;
						}
					case TETRAHEDRON:
						{
							file << "Tetrahedron and Tetrahedron:" << endl;
							break;
						}
					default:
						{
							file << "Unknown type" << endl;
							break;
						}
					}
					break;
				}
			default:
				{	
					file << "Unknown type" << endl;
					break;
				}
			}
			Out(temp1->shape, file);
			file << ", V = " << Volume(temp1->shape) << endl;
			Out(temp2->shape, file);
			file << ", V = " << Volume(temp2->shape) << endl << endl;; 
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}
