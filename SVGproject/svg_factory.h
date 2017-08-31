#include "rectangle.h"
#include "circle.h"
#include "line.h"

class SVG_Factory
{
public:
	SVG_Factory();

	Shape* createShape(std::string) const;
};