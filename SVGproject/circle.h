#include "shape.h"

class Circle : public Shape
{
private:
	int cx;
	int cy;
	int radius;
	char* fill;
public:

	Circle(char const*, int, int, int);

	Circle(Circle const&);

	Circle& operator=(Circle const&);

	virtual ~Circle();

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool IsWithin(Rectangle const&) const;

	virtual bool IsWithin(Circle const&) const;

	virtual void Translate(int, int);
};