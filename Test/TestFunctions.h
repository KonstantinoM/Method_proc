#include "stdafx.h"
#include "..\Met3\Container.h"
#include "..\Met3\Enu.h"

bool CompareFiles(ifstream &f1, ifstream &f2);
bool ComparePointerInContainer(cont *list1, cont *list2);
bool CompareContainer(cont *list1, cont *list2);
void ContainerPattern(cont *&list);
void SortContainerPattern(cont *&list);
void OneSphereInContainerPattern(cont *&list);
void OneBoxInContainerPattern(cont *&list);
void OneTetrahedronInContainerPattern(cont *&list);