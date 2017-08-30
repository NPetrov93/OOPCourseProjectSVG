#include "stdafx.h"
#include "line.h"
#include <cmath>

Line::Line(char const* _fill, int _x1, int _y1, int _x2, int _y2) :
Shape(_fill), x1(_x1), y1(_y1), y2(_y2), x2(_x2) { }

Line::Line(Line const& line) : Shape(line)
{
	x1 = line.x1;
	y1 = line.y1;

	x2 = line.x2;
	y2 = line.y2;
}

Line& Line::operator=(Line const& line)
{
	if (this != &line)
	{
		Shape::operator=(line);
		x1 = line.x1;
		y1 = line.y1;

		x2 = line.x2;
		y2 = line.y2;
	}
	return *this;
}

Line::~Line() { }

void Line::print(std::ostream& os) const
{
	os << "line" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
	Shape::print(os);
}

bool Line::IsWithin(Rectangle const& rect) const
{
	return true;
}

bool Line::IsWithin(Circle const& circle) const
{
	return true;
}

void Line::Translate(int vertical, int horizontal)
{
	x1 += vertical;
	y1 += horizontal;

	x2 += vertical;
	y2 += horizontal;
}

double Line::length()
{
	int x = (x1 - x2);
	int y = (y1 - y2);
	return sqrt(x*x + y*y);
}
