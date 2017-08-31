#include "stdafx.h"

#include <cstring>
#include "shape.h"

Shape::Shape(char const* _fill) : fill(nullptr)
{
	setFill(_fill);
}

Shape::Shape(Shape const& shape) {
	setFill(shape.fill);
}

Shape& Shape::operator=(Shape const& shape)
{
	if (this != &shape) {
		setFill(shape.fill);
	}
	return *this;
}

Shape::~Shape() {
	delete[] fill;
}

double Shape::findDistance(int x1, int y1, int x2, int y2) const
{
	int x = (x1 - x2);
	int y = (y1 - y2);
	double result = sqrt(x*x + y*y);
	return result;
}

void Shape::setFill(char const* _fill) {
	delete[] fill;
	if (_fill != nullptr) {
		int len = strlen(_fill);
		fill = new char[len + 1];
		strcpy_s(fill, len + 1, _fill);
	}
	else
		fill = nullptr;
}

void Shape::serializeFill(std::ostream& os) const
{
	serializeKeyStringValue(os, KEY_FILL, fill);
}

bool Shape::serialize(std::ostream& os) const
{
	startSerialize(os);
	serializeFill(os);
	finishSerialize(os);
	return os.good();
}

void Shape::print(std::ostream& os) const {
	os << fill << " ";
}
