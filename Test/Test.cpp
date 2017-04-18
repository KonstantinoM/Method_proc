#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "gtest/gtest.h"
#include "TestFunctions.h"
#include "..\Met3\Enu.h"
using namespace std;

TEST(SphereTest, SphereInput)
{
	ifstream f("SphereInput.txt");
	Sphere *actual, *expected;
	expected = new Sphere;
	actual = InSphere(f);
	expected->key = SPHERE;
	expected->r = 5;
	EXPECT_TRUE(actual->key==expected->key);
	EXPECT_TRUE(actual->r==expected->r);
}

TEST(SphereTest, SphereOutput)
{
	ofstream f("SphereOutput.txt");
	Sphere* actual = new Sphere;
	actual->key = SPHERE;
	actual->r = 4;
	OutSphere(actual, f);
	f.close();
	ifstream f1("SphereOutput.txt"), f2("SphereOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(SphereTest, SphereVolume)
{
	Sphere *actual = new Sphere;
	actual->key = SPHERE;
	actual->r = 1;
	float ActualVolume = VolumeSphere(actual);
	float ExpectedVolume = 4.18879;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(BoxTest, BoxInput)
{
	ifstream f("BoxInput.txt");
	Box *actual, *expected;
	expected = new Box;
	actual = InBox(f);
	expected->key = BOX;
	expected->a = 2;
	expected->b = 3;
	expected->c = 4;
	EXPECT_TRUE(actual->key == expected->key);
	EXPECT_TRUE(actual->a == expected->a);
	EXPECT_TRUE(actual->b == expected->b);
	EXPECT_TRUE(actual->c == expected->c);
}

TEST(BoxTest, BoxOutput)
{
	ofstream f("BoxOutput.txt");
	Box* actual = new Box;
	actual->key = BOX;
	actual->a = 3;
	actual->b = 5;
	actual->c = 9;
	OutBox(actual, f);
	f.close();
	ifstream f1("BoxOutput.txt"), f2("BoxOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(BoxTest, BoxVolume)
{
	Box *actual = new Box;
	actual->key = BOX;
	actual->a = 7;
	actual->b = 5;
	actual->c = 9;
	float ActualVolume = VolumeBox(actual);
	float ExpectedVolume = 315;
	EXPECT_EQ(ExpectedVolume, ActualVolume);
}

TEST(TetrahedronTest, TetrahedronInput)
{
	ifstream f("TetrahedronInput.txt");
	Tetrahedron *actual, *expected;
	expected = new Tetrahedron;
	expected->key = TETRAHEDRON;
	expected->a = 14;
	actual = InTetrahedron(f);
	EXPECT_TRUE(actual->key == expected->key);
	EXPECT_TRUE(actual->a == expected->a);
}

TEST(TetrahedronTest, TetrahedronOutput)
{
	ofstream f("TetrahedronOutput.txt");
	Tetrahedron* actual = new Tetrahedron;
	actual->key = TETRAHEDRON;
	actual->a = 183;
	OutTetrahedron(actual, f);
	f.close();
	ifstream f1("TetrahedronOutput.txt"), f2("TetrahedronOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(TetrahedronTest, TetrahedronVolume)
{
	Tetrahedron* actual = new Tetrahedron;
	actual->key = TETRAHEDRON;
	actual->a = 9;
	float ActualVolume = VolumeTetrahedron(actual);
	float ExpectedVolume = 85.9135;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.0001);
}

TEST(InputShapeTest, InputSphereToShape)
{
	ifstream f("InputSphereToShape.txt");
	Shape *actual = In(f);
	Shape *expected = new Shape;
	((Sphere *)expected)->r = 2;
	expected->key = SPHERE;
	expected->p = 5;
	expected->t = 65;
	EXPECT_TRUE(((Sphere *)expected)->r == ((Sphere *)actual)->r);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->p == actual->p);
	EXPECT_TRUE(expected->t == actual->t);
}

TEST(InputShapeTest, InputBoxToShape)
{
	ifstream f("InputBoxToShape.txt");
	Shape *actual = In(f);
	Shape *expected = new Shape;
	((Box *)expected)->a = 2;
	((Box *)expected)->b = 3;
	((Box *)expected)->c = 4;
	expected->key = BOX;
	expected->p = 67;
	expected->t = 987;
	EXPECT_TRUE(((Box *)expected)->a == ((Box *)actual)->a);
	EXPECT_TRUE(((Box *)expected)->b == ((Box *)actual)->b);
	EXPECT_TRUE(((Box *)expected)->c == ((Box *)actual)->c);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->p == actual->p);
	EXPECT_TRUE(expected->t == actual->t);
}

TEST(InputShapeTest, InputTetrahedronToShape)
{
	ifstream f("InputTetrahedronToShape.txt");
	Shape *actual = In(f);
	Shape *expected = new Shape;
	((Tetrahedron *)expected)->a = 25;
	expected->key = TETRAHEDRON;
	expected->p = 75;
	expected->t = 698;
	EXPECT_TRUE(((Tetrahedron *)expected)->a == ((Tetrahedron *)actual)->a);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->p == actual->p);
	EXPECT_TRUE(expected->t == actual->t);
}

TEST(OutputShapeTest, ShapeBoxOutput)
{
	ofstream f("ShapeBoxOutput.txt");
	Shape *actual = new Shape;
	((Box*)actual)->key = BOX;
	((Box *)actual)->a = 2;
	((Box *)actual)->b = 3;
	((Box *)actual)->c = 4;
	actual->key = BOX;
	actual->p = 5;
	actual->t = 65;
	Out(actual, f);
	f.close();
	ifstream f1("ShapeBoxOutput.txt"), f2("ShapeBoxOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputShapeTest, ShapeSphereOutput)
{
	ofstream f("ShapeSphereOutput.txt");
	Shape *actual = new Shape;
	((Sphere*)actual)->key = SPHERE;
	((Sphere *)actual)->r = 2;
	actual->key = SPHERE;
	actual->p = 5;
	actual->t = 65;
	Out(actual, f);
	f.close();
	ifstream f1("ShapeSphereOutput.txt"), f2("ShapeSphereOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOutput)
{
	ofstream f("ShapeTetrahedronOutput.txt");
	Shape *actual = new Shape;
	((Tetrahedron*)actual)->key = TETRAHEDRON;
	((Tetrahedron *)actual)->a = 25;
	actual->key = TETRAHEDRON;
	actual->p = 5;
	actual->t = 65;
	Out(actual, f);
	f.close();
	ifstream f1("ShapeTetrahedronOutput.txt"), f2("ShapeTetrahedronOutputPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(ShapeVolumeTest, ShapeSphereVolume)
{
	Shape *actual = new Shape;
	((Sphere*)actual)->key = SPHERE;
	((Sphere*)actual)->r = 1;
	actual->key = SPHERE;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 4.18879;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(ShapeVolumeTest, ShapeBoxVolume)
{
	Shape *actual = new Shape;
	((Box*)actual)->key = BOX;
	((Box*)actual)->a = 7;
	((Box*)actual)->b = 5;
	((Box*)actual)->c = 9;
	actual->key = BOX;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 315;
	EXPECT_EQ(ExpectedVolume, ActualVolume);
}

TEST(ShapeVolumeTest, ShapeTetrahedronVolume)
{
	Shape *actual = new Shape;
	((Tetrahedron*)actual)->key = TETRAHEDRON;
	((Tetrahedron*)actual)->a = 9;
	actual->key = TETRAHEDRON;
	float ActualVolume = Volume(actual);
	float ExpectedVolume = 85.9135;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.0001);
}

TEST(ShapeCompareVolumeTest, CompareVolumeMore)
{	
	Shape *shape1 = new Shape;
	((Tetrahedron*)shape1)->key = TETRAHEDRON;
	((Tetrahedron*)shape1)->a = 9;
	shape1->key = TETRAHEDRON;

	Shape *shape2 = new Shape;
	((Box*)shape2)->key = BOX;
	((Box*)shape2)->a = 7;
	((Box*)shape2)->b = 6;
	((Box*)shape2)->c = 2;
	shape2->key = BOX;
	EXPECT_TRUE(Compare(shape1, shape2));
}

TEST(ShapeCompareVolumeTest, CompareVolumeLess)
{	
	Shape *shape1 = new Shape;
	((Tetrahedron*)shape1)->key = TETRAHEDRON;
	((Tetrahedron*)shape1)->a = 9;
	shape1->key = TETRAHEDRON;

	Shape *shape2 = new Shape;
	((Box*)shape2)->key = BOX;
	((Box*)shape2)->a = 7;
	((Box*)shape2)->b = 6;
	((Box*)shape2)->c = 2;
	shape2->key = BOX;
	EXPECT_TRUE(!Compare(shape2, shape1));
}

TEST(ShapeCompareVolumeTest, CompareVolumeEqual)
{	
	Shape *shape1 = new Shape;
	((Tetrahedron*)shape1)->key = TETRAHEDRON;
	((Tetrahedron*)shape1)->a = 9;
	shape1->key = TETRAHEDRON;

	EXPECT_TRUE(!Compare(shape1, shape1));
}

TEST(InitContainerTest, InitContainer)
{
	cont *list = NULL;
	Init(list);
	EXPECT_TRUE(list->sh == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	cont *list = new cont;
	list->sh = NULL;
	list->n = 0;
	list->next = list; 
	list->prev = list;
	Clear(list);
	EXPECT_TRUE(list->sh == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	cont *list = new cont;
	list->sh = new Shape;
	list->n = 1;
	list->next = list; 
	list->prev = list;
	Clear(list);
	EXPECT_TRUE(list->sh == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream f("OneSphereInContainer.txt");
	cont *actual = new cont;
	actual->sh = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	Incont(actual, f);

	cont *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneBoxInContainer)
{
	ifstream f("OneBoxInContainer.txt");
	cont *actual = new cont;
	actual->sh = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	Incont(actual, f);

	cont *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream f("OneTetrahedronInContainer.txt");
	cont *actual = new cont;
	actual->sh = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	Incont(actual, f);

	cont *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, NoElementsInContainer)
{
	ifstream f("NoElementsInContainer.txt");
	cont *actual = new cont;
	actual->sh = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	Incont(actual, f);

	cont *expected = new cont;
	expected->sh = NULL;
	expected->n = 0;
	expected->next = expected; 
	expected->prev = expected;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream f("SeveralElementsInContainer.txt");
	cont *actual = new cont;
	actual->sh = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	Incont(actual, f);

	cont *expected = NULL;
	ContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream f("SeveralElementOutContainer.txt");
	cont *actual = NULL;
	ContainerPattern(actual);
	Outcont(actual, f);
	f.close();

	ifstream f1("SeveralElementOutContainer.txt"), f2("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	ofstream f("OneSphereOutContainer.txt");
	cont *actual = NULL;
	OneSphereInContainerPattern(actual);
	Outcont(actual, f);
	f.close();

	ifstream f1("OneSphereOutContainer.txt"), f2("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, OneBoxOutContainer)
{
	ofstream f("OneBoxOutContainer.txt");
	cont *actual = NULL;
	OneBoxInContainerPattern(actual);
	Outcont(actual, f);
	f.close();

	ifstream f1("OneBoxOutContainer.txt"), f2("OneBoxOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream f("OneTetrahedronOutContainer.txt");
	cont *actual =  NULL;
	OneTetrahedronInContainerPattern(actual);
	Outcont(actual, f);
	f.close();

	ifstream f1("OneTetrahedronOutContainer.txt"), f2("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream f("NoElementsOutContainer.txt");
	cont *actual = new cont;
	actual->n = 0;
	actual->sh = NULL;
	actual->next = actual; 
	actual->prev = actual;
	Outcont(actual, f);
	f.close();

	ifstream f1("NoElementsOutContainer.txt"), f2("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream f("OnlySeveralSpheresOutContainer.txt");
	cont *actual = NULL;
	ContainerPattern(actual);
	OutcontOnlySphere(actual, f);
	f.close();

	ifstream f1("OnlySeveralSpheresOutContainer.txt"), f2("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream f("OnlySingleSpheresOutContainer.txt");
	cont *actual = NULL;
	OneSphereInContainerPattern(actual);
	OutcontOnlySphere(actual, f);
	f.close();

	ifstream f1("OnlySingleSpheresOutContainer.txt"), f2("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(OutputContainerTest,NoSpheresOutContainer)
{
	ofstream f("NoSpheresOutContainer.txt");
	cont *actual = new cont;
	actual->n = 0;
	actual->sh = NULL;
	actual->next = actual; 
	actual->prev = actual;
	OutcontOnlySphere(actual, f);
	f.close();

	ifstream f1("NoSpheresOutContainer.txt"), f2("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!f1);
	EXPECT_TRUE(CompareFiles(f1, f2));
	f1.close();
	f2.close();
}

TEST(SortContainerTest, JustSortContainer)
{
	cont *actual = NULL;
	ContainerPattern(actual);
	Sort(actual);

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	cont *actual = new cont;
	actual->n = 6;
	actual->sh = new Shape;
	((Sphere*)actual->sh)->key = SPHERE;
	((Sphere*)actual->sh)->r = 67;
	actual->sh->key = SPHERE;
	actual->sh->p = 87;
	actual->sh->t = 343;
	actual->next = actual; 
	actual->prev = actual;

	cont *temp = new cont;
	temp->sh = new Shape;
	((Sphere*)temp->sh)->key = SPHERE;
	((Sphere*)temp->sh)->r = 6;
	temp->sh->key = SPHERE;
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 5;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Box*)temp->sh)->key = BOX;
	((Box*)temp->sh)->a = 4;
	((Box*)temp->sh)->b = 12;
	((Box*)temp->sh)->c = 11;
	temp->sh->key = BOX;
	temp->sh->p = 123;
	temp->sh->t = 167;
	temp->n = 4;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

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
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new cont;	
	temp->sh = new Shape;
	((Tetrahedron*)temp->sh)->key = TETRAHEDRON;
	((Tetrahedron*)temp->sh)->a = 9;
	temp->sh->key = TETRAHEDRON;
	temp->sh->p = 98;
	temp->sh->t = 354;
	temp->n = 2;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new cont;
	temp->sh = new Shape;
	((Tetrahedron*)temp->sh)->key = TETRAHEDRON;
	((Tetrahedron*)temp->sh)->a = 3;
	temp->sh->key = TETRAHEDRON;
	temp->sh->p = 5;
	temp->sh->t = 34;
	temp->n = 1;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	Sort(actual);

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, SortedSortContainer)
{
	cont *actual = NULL;
	SortContainerPattern(actual);
	Sort(actual);

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	cont *actual = NULL;
	OneSphereInContainerPattern(actual);
	Sort(actual);

	cont *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneBoxInContainer)
{
	cont *actual = NULL;
	OneBoxInContainerPattern(actual);
	Sort(actual);

	cont *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}


TEST(SortContainerTest, OneTetrahedronInContainer)
{
	cont *actual = NULL;
	OneTetrahedronInContainerPattern(actual);
	Sort(actual);

	cont *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	cont *actual = new cont;
	actual->n = 0;
	actual->sh = NULL;
	actual->next = actual; 
	actual->prev = actual;
	Sort(actual);

	cont *expected = new cont;
	expected->n = 0;
	expected->sh = NULL;
	expected->next = expected; 
	expected->prev = expected;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

int main(int argc, char **argv) 
{ 
	::testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	system("pause"); 
	return 0; 
}