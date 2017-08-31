#include "stdafx.h"
#include "circle.h"
#include <sstream>

const char* Circle::TYPENAME = "circle";

Circle::Circle() : Shape(nullptr), cx(0), cy(0), radius(0) { }

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

int Circle::getCX() const
{
	return cx;
}

int Circle::getCY() const
{
	return cy;
}

int Circle::getRadius() const
{
	return radius;
}

bool Circle::pointIsInside(int _x, int _y) const
{
	if (Shape::findDistance(_x, _y, cx, cy) <= radius)
		return true;

	return false;
}

void Circle::Translate(int vertical, int horizontal)
{
	cx += vertical;
	cy += horizontal;
}

bool Circle::serialize(std::ostream& os) const
{
	startSerialize(os);
	serializeType(os);
	serializeCX(os);
	serializeCY(os);
	serializeRadius(os);
	serializeFill(os);
	finishSerialize(os);
	return os.good();
}

void Circle::print(std::ostream& os) const
{
	os << "circle" << " " << cx << " " << cy << " " << radius << " ";
	Shape::print(os);
}

void Circle::serializeCX(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_CX, getCX());
}

void Circle::serializeCY(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_CY, getCY());
}

void Circle::serializeRadius(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_RADIUS, getRadius());
}

bool Circle::deserialize(std::istream& is)
{
	std::string key;
	std::string value;
	while (deserializeKeyValuePair(is, key, value))
	{
		setKeyValuePair(key, value);
	}
	return is.good();
}

void Circle::setKeyValuePair(std::string key, std::string value)
{
	if (key == KEY_FILL)
	{
		const char* fill = value.c_str();
		setFill(fill);
	}
	else
	{
		std::stringstream geek(value);
		if (key == KEY_CX)
		{
			geek >> cx;
		}
		else if (key == KEY_CY)
		{
			geek >> cy;
		}
		else if (key == KEY_RADIUS)
		{
			geek >> radius;
		}
	}
}