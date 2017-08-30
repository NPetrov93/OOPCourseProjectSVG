#include "shape.h"

class Line : public Shape
{
public:
	Line(char const*, int, int, int, int);

	Line(Line const&);

	Line& operator=(Line const&);

	virtual ~Line();

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool IsWithin(Rectangle const&) const;

	virtual bool IsWithin(Circle const&) const;

	virtual void Translate(int, int);

	double length();

private:
	int x1;
	int y1;

	int x2;
	int y2;
};