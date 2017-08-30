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

Shape::~Shape() {
	delete[] fill;
}

Shape& Shape::operator=(Shape const& shape)
{
	if (this != &shape) {
		setFill(shape.fill);
	}
	return *this;
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

void Shape::print(std::ostream& os) const {
	os << fill << " ";
}
