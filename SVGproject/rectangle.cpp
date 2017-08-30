#include "stdafx.h"
#include "rectangle.h"

Rectangle::Rectangle(const char* _fill, int _x, int _y, int _width, int _height) : Shape(_fill), x(_x), y(_y), width(_width), height(_height) { }

Rectangle::Rectangle(Rectangle const& rect) : Shape(rect)
{
	x = rect.x;
	y = rect.y;
	width = rect.width;
	height = rect.height;
}

Rectangle& Rectangle::operator=(Rectangle const& rect)
{
	if (this != &rect)
	{
		Shape::operator=(rect);
		x = rect.x;
		y = rect.y;
		width = rect.width;
		height = rect.height;
	}
	return *this;
}

Rectangle::~Rectangle() { }

void Rectangle::print(std::ostream& os) const
{
	os << "rectangle" << " " << x << " " << y << " " << width << " " << height << " ";
	Shape::print(os);
}

bool Rectangle::IsWithin(Rectangle const& rect) const
{
	if (x >= rect.x && y >= rect.y && x + height <= rect.x + rect.height && y + width <= rect.y + rect.width)
		return true;

	return false;
}

bool Rectangle::IsWithin(Circle const& cirlce) const
{
	return true;
}

void Rectangle::Translate(int vertical, int horizontal)
{
	x += vertical;
	y += horizontal;
}