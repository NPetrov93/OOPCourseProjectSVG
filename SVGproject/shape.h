#pragma once

#ifndef SHAPE_H_
#define SHAPE_H_

#include "printable.h"

class Rectangle;
class Circle;

enum Fill {
	GREEN = 1,
	RED = 2
};

class Shape
{
private:
	char* fill;

	void setFill(char const* _fill);
public:

	Shape(char const*);

	Shape(Shape const&);

	Shape& operator=(Shape const&);

	virtual ~Shape();

	virtual bool IsWithin(Rectangle const&) const = 0;

	virtual bool IsWithin(Circle const&) const = 0;

	virtual void Translate(int, int) = 0;

	virtual void print(std::ostream& os = std::cout) const;
};

#endif /* SHAPE_H_ */