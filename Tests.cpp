#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "gtest/gtest.h"
#include "..\Met3\Sphere.h"
#include "..\Met3\Enu.h"
using namespace std;

class Tests : public ::testing::Test {
};

TEST(Tests, InputSphereTest)
{
	ifstream f("Sphere.txt");
	Sphere *s;
	s = InSphere(f);
	ASSERT_TRUE((s->key==SPHERE)&&(s->r==5));
}

int main(int argc, char **argv) 
{ 
	::testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	system("pause"); 
	return 0; 
}