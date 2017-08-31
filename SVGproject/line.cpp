#include "stdafx.h"
#include "line.h"
#include<sstream>
#include <cmath>

const char* Line::TYPENAME = "line";

Line::Line() : Shape(nullptr), x1(0), y1(0), x2(0), y2(0) { }

Line::Line(char const* _fill, int _x1, int _y1, int _x2, int _y2) : Shape(_fill), x1(_x1), y1(_y1), y2(_y2), x2(_x2) { }

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

void Line::Translate(int vertical, int horizontal)
{
	x1 += vertical;
	y1 += horizontal;

	x2 += vertical;
	y2 += horizontal;
}

void Line::print(std::ostream& os) const
{
	os << "line" << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
	Shape::print(os);
}

bool Line::serialize(std::ostream& os) const
{
	startSerialize(os);
	serializeType(os);
	serializeX1(os);
	serializeY1(os);
	serializeX2(os);
	serializeY2(os);
	serializeFill(os);
	finishSerialize(os);
	return os.good();
}

void Line::serializeX1(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_X1_COORD, getX1());
}
void Line::serializeY1(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_Y1_COORD, getY1());
}

void Line::serializeX2(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_X2_COORD, getX2());
}

void Line::serializeY2(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_Y2_COORD, getY2());
}

bool Line::deserialize(std::istream& is)
{
	std::string key;
	std::string value;
	while (deserializeKeyValuePair(is, key, value))
	{
		setKeyValuePair(key, value);
	}
	return is.good();
}

void Line::setKeyValuePair(std::string key, std::string value)
{
	if (key == KEY_FILL)
	{
		const char* fillVal = value.c_str();
		setFill(fillVal);
	}
	else
	{
		std::stringstream geek(value);
		if (key == KEY_X1_COORD)
		{
			geek >> x1;
		}
		else if (key == KEY_Y1_COORD)
		{
			geek >> y1;
		}
		else if (key == KEY_X2_COORD)
		{
			geek >> x2;
		}
		else if (key == KEY_Y2_COORD)
		{
			geek >> y2;
		}
	}
}