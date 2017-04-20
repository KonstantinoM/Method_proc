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
	ifstream file("SphereInput.txt");
	Sphere *actual, *expected;
	expected = new Sphere;
	actual = InSphere(file);
	expected->key = SPHERE;
	expected->r = 5;
	EXPECT_TRUE(actual->key == expected->key);
	EXPECT_TRUE(actual->r == expected->r);
}

TEST(SphereTest, SphereOutput)
{
	ofstream file("SphereOutput.txt");
	Sphere* sphere = new Sphere;
	sphere->key = SPHERE;
	sphere->r = 4;
	OutSphere(sphere, file);
	file.close();
	ifstream actualFile("SphereOutput.txt"), expectedFile("SphereOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ifstream file("BoxInput.txt");
	Box *actual, *expected;
	expected = new Box;
	actual = InBox(file);
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
	ofstream file("BoxOutput.txt");
	Box* box = new Box;
	box->key = BOX;
	box->a = 3;
	box->b = 5;
	box->c = 9;
	OutBox(box, file);
	file.close();
	ifstream actualFile("BoxOutput.txt"), expectedFile("BoxOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ifstream file("TetrahedronInput.txt");
	Tetrahedron *actual, *expected;
	expected = new Tetrahedron;
	expected->key = TETRAHEDRON;
	expected->a = 14;
	actual = InTetrahedron(file);
	EXPECT_TRUE(actual->key == expected->key);
	EXPECT_TRUE(actual->a == expected->a);
}

TEST(TetrahedronTest, TetrahedronOutput)
{
	ofstream file("TetrahedronOutput.txt");
	Tetrahedron* tetrahedron = new Tetrahedron;
	tetrahedron->key = TETRAHEDRON;
	tetrahedron->a = 183;
	OutTetrahedron(tetrahedron, file);
	file.close();
	ifstream actualFile("TetrahedronOutput.txt"), expectedFile("TetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ifstream file("InputSphereToShape.txt");
	Shape *actual = In(file);
	Shape *expected = new Shape;
	((Sphere *)expected)->r = 2;
	expected->key = SPHERE;
	expected->density = 5;
	expected->temperature = 65;
	EXPECT_TRUE(((Sphere *)expected)->r == ((Sphere *)actual)->r);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->density == actual->density);
	EXPECT_TRUE(expected->temperature == actual->temperature);
}

TEST(InputShapeTest, InputBoxToShape)
{
	ifstream file("InputBoxToShape.txt");
	Shape *actual = In(file);
	Shape *expected = new Shape;
	((Box *)expected)->a = 2;
	((Box *)expected)->b = 3;
	((Box *)expected)->c = 4;
	expected->key = BOX;
	expected->density = 67;
	expected->temperature = 987;
	EXPECT_TRUE(((Box *)expected)->a == ((Box *)actual)->a);
	EXPECT_TRUE(((Box *)expected)->b == ((Box *)actual)->b);
	EXPECT_TRUE(((Box *)expected)->c == ((Box *)actual)->c);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->density == actual->density);
	EXPECT_TRUE(expected->temperature == actual->temperature);
}

TEST(InputShapeTest, InputTetrahedronToShape)
{
	ifstream file("InputTetrahedronToShape.txt");
	Shape *actual = In(file);
	Shape *expected = new Shape;
	((Tetrahedron *)expected)->a = 25;
	expected->key = TETRAHEDRON;
	expected->density = 75;
	expected->temperature = 698;
	EXPECT_TRUE(((Tetrahedron *)expected)->a == ((Tetrahedron *)actual)->a);
	EXPECT_TRUE(expected->key == actual->key);
	EXPECT_TRUE(expected->density == actual->density);
	EXPECT_TRUE(expected->temperature == actual->temperature);
}

TEST(OutputShapeTest, ShapeBoxOutput)
{
	ofstream file("ShapeBoxOutput.txt");
	Shape *box = new Shape;
	((Box*)box)->key = BOX;
	((Box *)box)->a = 2;
	((Box *)box)->b = 3;
	((Box *)box)->c = 4;
	box->key = BOX;
	box->density = 5;
	box->temperature = 65;
	Out(box, file);
	file.close();
	ifstream actualFile("ShapeBoxOutput.txt"), expectedFile("ShapeBoxOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeSphereOutput)
{
	ofstream file("ShapeSphereOutput.txt");
	Shape *shape = new Shape;
	((Sphere*)shape)->key = SPHERE;
	((Sphere *)shape)->r = 2;
	shape->key = SPHERE;
	shape->density = 5;
	shape->temperature = 65;
	Out(shape, file);
	file.close();
	ifstream actualFile("ShapeSphereOutput.txt"), expectedFile("ShapeSphereOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOutput)
{
	ofstream file("ShapeTetrahedronOutput.txt");
	Shape *shape = new Shape;
	((Tetrahedron*)shape)->key = TETRAHEDRON;
	((Tetrahedron *)shape)->a = 25;
	shape->key = TETRAHEDRON;
	shape->density = 5;
	shape->temperature = 65;
	Out(shape, file);
	file.close();
	ifstream actualFile("ShapeTetrahedronOutput.txt"), expectedFile("ShapeTetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	Container *list = NULL;
	Init(list);
	EXPECT_TRUE(list->shape == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	Container *list = new Container;
	list->shape = NULL;
	list->n = 0;
	list->next = list; 
	list->prev = list;
	Clear(list);
	EXPECT_TRUE(list->shape == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	Container *list = new Container;
	list->shape = new Shape;
	list->n = 1;
	list->next = list; 
	list->prev = list;
	Clear(list);
	EXPECT_TRUE(list->shape == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream file("OneSphereInContainer.txt");
	Container *actual = new Container;
	actual->shape = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	InContainer(actual, file);

	Container *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneBoxInContainer)
{
	ifstream file("OneBoxInContainer.txt");
	Container *actual = new Container;
	actual->shape = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	InContainer(actual, file);

	Container *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream file("OneTetrahedronInContainer.txt");
	Container *actual = new Container;
	actual->shape = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	InContainer(actual, file);

	Container *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

//There is no nesessity to run this test because of Secure Coding.

//TEST(InputContainerTest, NoElementsInContainer)
//{
//	ifstream file("NoElementsInContainer.txt");
//	Container *actual = new Container;
//	actual->shape = NULL;
//	actual->n = 0;
//	actual->next = actual; 
//	actual->prev = actual;
//	InContainer(actual, file);
//
//	Container *expected = new Container;
//	expected->shape = NULL;
//	expected->n = 0;
//	expected->next = expected; 
//	expected->prev = expected;
//	EXPECT_TRUE(CompareContainer(actual, expected));
//}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream file("SeveralElementsInContainer.txt");
	Container *actual = new Container;
	actual->shape = NULL;
	actual->n = 0;
	actual->next = actual; 
	actual->prev = actual;
	InContainer(actual, file);

	Container *expected = NULL;
	ContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream file("SeveralElementOutContainer.txt");
	Container *actual = NULL;
	ContainerPattern(actual);
	OutContainer(actual, file);
	file.close();

	ifstream actualFile("SeveralElementOutContainer.txt"), expectedFile("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	ofstream file("OneSphereOutContainer.txt");
	Container *actual = NULL;
	OneSphereInContainerPattern(actual);
	OutContainer(actual, file);
	file.close();

	ifstream actualFile("OneSphereOutContainer.txt"), expectedFile("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneBoxOutContainer)
{
	ofstream file("OneBoxOutContainer.txt");
	Container *actual = NULL;
	OneBoxInContainerPattern(actual);
	OutContainer(actual, file);
	file.close();

	ifstream actualFile("OneBoxOutContainer.txt"), expectedFile("OneBoxOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream file("OneTetrahedronOutContainer.txt");
	Container *actual =  NULL;
	OneTetrahedronInContainerPattern(actual);
	OutContainer(actual, file);
	file.close();

	ifstream actualFile("OneTetrahedronOutContainer.txt"), expectedFile("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream file("NoElementsOutContainer.txt");
	Container *actual = new Container;
	actual->n = 0;
	actual->shape = NULL;
	actual->next = actual; 
	actual->prev = actual;
	OutContainer(actual, file);
	file.close();

	ifstream actualFile("NoElementsOutContainer.txt"), expectedFile("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream file("OnlySeveralSpheresOutContainer.txt");
	Container *actual = NULL;
	ContainerPattern(actual);
	OutContainerOnlySphere(actual, file);
	file.close();

	ifstream actualFile("OnlySeveralSpheresOutContainer.txt"), expectedFile("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream file("OnlySingleSpheresOutContainer.txt");
	Container *actual = NULL;
	OneSphereInContainerPattern(actual);
	OutContainerOnlySphere(actual, file);
	file.close();

	ifstream actualFile("OnlySingleSpheresOutContainer.txt"), expectedFile("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest,NoSpheresOutContainer)
{
	ofstream file("NoSpheresOutContainer.txt");
	Container *actual = new Container;
	actual->n = 0;
	actual->shape = NULL;
	actual->next = actual; 
	actual->prev = actual;
	OutContainerOnlySphere(actual, file);
	file.close();

	ifstream actualFile("NoSpheresOutContainer.txt"),expectedFile("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SortContainerTest, JustSortContainer)
{
	Container *actual = NULL;
	ContainerPattern(actual);
	Sort(actual);

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	Container *actual = new Container;
	actual->n = 6;
	actual->shape = new Shape;
	((Sphere*)actual->shape)->key = SPHERE;
	((Sphere*)actual->shape)->r = 67;
	actual->shape->key = SPHERE;
	actual->shape->density = 87;
	actual->shape->temperature = 343;
	actual->next = actual; 
	actual->prev = actual;

	Container *temp = new Container;
	temp->shape = new Shape;
	((Sphere*)temp->shape)->key = SPHERE;
	((Sphere*)temp->shape)->r = 6;
	temp->shape->key = SPHERE;
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 5;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 4;
	((Box*)temp->shape)->b = 12;
	((Box*)temp->shape)->c = 11;
	temp->shape->key = BOX;
	temp->shape->density = 123;
	temp->shape->temperature = 167;
	temp->n = 4;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Box*)temp->shape)->key = BOX;
	((Box*)temp->shape)->a = 10;
	((Box*)temp->shape)->b = 8;
	((Box*)temp->shape)->c = 6;
	temp->shape->key = BOX;
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 3;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new Container;	
	temp->shape = new Shape;
	((Tetrahedron*)temp->shape)->key = TETRAHEDRON;
	((Tetrahedron*)temp->shape)->a = 9;
	temp->shape->key = TETRAHEDRON;
	temp->shape->density = 98;
	temp->shape->temperature = 354;
	temp->n = 2;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;

	temp = new Container;
	temp->shape = new Shape;
	((Tetrahedron*)temp->shape)->key = TETRAHEDRON;
	((Tetrahedron*)temp->shape)->a = 3;
	temp->shape->key = TETRAHEDRON;
	temp->shape->density = 5;
	temp->shape->temperature = 34;
	temp->n = 1;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	Sort(actual);

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, SortedSortContainer)
{
	Container *actual = NULL;
	SortContainerPattern(actual);
	Sort(actual);

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	Container *actual = NULL;
	OneSphereInContainerPattern(actual);
	Sort(actual);

	Container *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneBoxInContainer)
{
	Container *actual = NULL;
	OneBoxInContainerPattern(actual);
	Sort(actual);

	Container *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}


TEST(SortContainerTest, OneTetrahedronInContainer)
{
	Container *actual = NULL;
	OneTetrahedronInContainerPattern(actual);
	Sort(actual);

	Container *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	Container *actual = new Container;
	actual->n = 0;
	actual->shape = NULL;
	actual->next = actual; 
	actual->prev = actual;
	Sort(actual);

	Container *expected = new Container;
	expected->n = 0;
	expected->shape = NULL;
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