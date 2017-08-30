#include "shape.h"

class Rectangle : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;
	char* fill;
public:

	Rectangle(char const*, int, int, int, int);

	Rectangle(Rectangle const&);

	Rectangle& operator=(Rectangle const&);

	virtual ~Rectangle();

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool IsWithin(Rectangle const&) const;

	virtual bool IsWithin(Circle const&) const;

	virtual void Translate(int, int);
};