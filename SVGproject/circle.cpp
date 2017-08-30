#include "stdafx.h"
#include "circle.h"

#include<iostream>
using namespace std;

Circle::Circle(char const* _fill, int _cx, int _cy, int _radius) : Shape(_fill), cx(_cx), cy(_cy), radius(_radius) { }

Circle::Circle(Circle const& circle) : Shape(circle)
{
	cx = circle.cx;
	cy = circle.cy;
	radius = circle.radius;
}

Circle& Circle::operator=(Circle const& circle)
{
	if (this != &circle)
	{
		Shape::operator=(circle);
		cx = circle.cx;
		cy = circle.cy;
		radius = circle.radius;
	}
	return *this;
}

Circle::~Circle() { }

void Circle::print(std::ostream& os) const
{
	os << "circle" << " " << cx << " " << cy << " " << radius << " ";
	Shape::print(os);
}

bool Circle::IsWithin(Rectangle const& rect) const
{
	return true;
}

bool Circle::IsWithin(Circle const& cirlce) const
{
	return true;
}

void Circle::Translate(int vertical, int horizontal)
{
	cx += vertical;
	cy += horizontal;
}