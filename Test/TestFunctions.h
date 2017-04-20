#include "stdafx.h"
#include "..\Met3\Container.h"
#include "..\Met3\Enu.h"

bool CompareFiles(ifstream &f1, ifstream &f2);
bool ComparePointerInContainer(Container *list1, Container *list2);
bool CompareContainer(Container *list1, Container *list2);
void ContainerPattern(Container *&list);
void SortContainerPattern(Container *&list);
void OneSphereInContainerPattern(Container *&list);
void OneBoxInContainerPattern(Container *&list);
void OneTetrahedronInContainerPattern(Container *&list);