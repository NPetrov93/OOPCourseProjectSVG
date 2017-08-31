#include "stdafx.h"
#include "rectangle.h"
#include <sstream>

const char* Rectangle::TYPENAME = "rect";

Rectangle::Rectangle() : Shape(nullptr), x(0), y(0), width(0), height(0) { }

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

int Rectangle::getX() const
{
	return x;
}

int Rectangle::getY() const
{
	return y;
}

int Rectangle::getWidth() const
{
	return width;
}

int Rectangle::getHeight() const
{
	return height;
}

bool Rectangle::pointIsInside(int _x, int _y) const
{
	if (_x >= x && _x <= x + width && _y >= y && _y <= y + height)
		return true;

	return false;
}

void Rectangle::Translate(int vertical, int horizontal)
{
	x += vertical;
	y += horizontal;
}

void Rectangle::print(std::ostream& os) const
{
	os << "rectangle" << " " << x << " " << y << " " << width << " " << height << " ";
	Shape::print(os);
}

void Rectangle::serializeX(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_X_COORD, getX());
}

void Rectangle::serializeY(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_Y_COORD, getY());
}

void Rectangle::serializeWidth(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_WIDTH, getWidth());
}

void Rectangle::serializeHeight(std::ostream& os) const
{
	serializeKeyIntValue(os, KEY_HEIGHT, getHeight());
}

bool Rectangle::serialize(std::ostream& os) const
{
	startSerialize(os);
	serializeType(os);
	serializeX(os);
	serializeY(os);
	serializeWidth(os);
	serializeHeight(os);
	serializeFill(os);
	finishSerialize(os);
	return os.good();
}

bool Rectangle::deserialize(std::istream& is)
{
	std::string key;
	std::string value;
	while (deserializeKeyValuePair(is, key, value))
	{
		setKeyValuePair(key, value);
	}
	return is.good();
}

void Rectangle::setKeyValuePair(std::string key, std::string value)
{
	if (key == KEY_FILL)
	{
		const char* fill = value.c_str();
		setFill(fill);
	}
	else
	{
		std::stringstream geek(value);
		if (key == KEY_X_COORD)
		{
			geek >> x;
		}
		else if (key == KEY_Y_COORD)
		{
			geek >> y;
		}
		else if (key == KEY_WIDTH)
		{
			geek >> width;
		}
		else if (key == KEY_HEIGHT)
		{
			geek >> height;
		}
	}
}