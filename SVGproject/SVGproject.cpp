// SVGproject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "rectangle.h"
#include "circle.h"
#include<iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	Rectangle* rect = new Rectangle("green", 5, 5, 10, 10);
	Circle* circle = new Circle("red", 10, 10, 5);

	Shape* shapes = rect;

	shapes->print();
	shapes = circle;
	cout << endl;
	shapes->print();
	cout << endl;

	shapes->Translate(17, 10);
	shapes->print();
	cout << endl;

	system("pause");
	return 0;
}

