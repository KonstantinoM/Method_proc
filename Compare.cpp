#include "stdafx.h"
#include "Shape.h"

bool Compare(Shape *shape1, Shape *shape2)
{
	return Volume(shape1) > Volume(shape2);
}
