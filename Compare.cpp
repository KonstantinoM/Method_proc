#include "stdafx.h"
#include "Shape.h"

bool Compare(Shape *f, Shape *s)
{
	return Volume(f) > Volume(s);
}
