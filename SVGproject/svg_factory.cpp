#include "stdafx.h"
#include "svg_factory.h"

SVG_Factory::SVG_Factory() { }

Shape* SVG_Factory::createShape(std::string str_type) const
{
	const char* type = str_type.c_str();
	if (strcmp(type, Line::TYPENAME) == 0)
	{
		return new Line();
	}
	else if (strcmp(type, Circle::TYPENAME) == 0)
	{
		return new Circle();
	}
	else if (strcmp(type, Rectangle::TYPENAME) == 0)
	{
		return new Rectangle();
	}

	return nullptr;
}