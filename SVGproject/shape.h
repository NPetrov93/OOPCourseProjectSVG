#pragma once

#ifndef SHAPE_H_
#define SHAPE_H_

#include "printable.h"
#include "svg_serializable.h"

const char KEY_FILL[] = "fill";

class Rectangle;
class Circle;
class Line;

enum Fill {
	GREEN = 1,
	RED = 2
};

class Shape : public SVGSerializable
{
private:
	char* fill;

protected:
	double findDistance(int x1, int y1, int x2, int y2) const;

	void setFill(char const* _fill);

	void serializeFill(std::ostream&) const;
public:

	Shape(char const*);

	Shape(Shape const&);

	Shape& operator=(Shape const&);

	virtual ~Shape();

	virtual bool IsWithin(Rectangle const&) const = 0;

	virtual bool IsWithin(Circle const&) const = 0;

	virtual void Translate(int, int) = 0;

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool serialize(std::ostream&) const;

	virtual bool deserialize(std::istream&) {
		return false;
	}
};

#endif /* SHAPE_H_ */