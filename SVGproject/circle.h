#include "shape.h"

const char KEY_CX[] = "cx";
const char KEY_CY[] = "cy";
const char KEY_RADIUS[] = "radius";

class Circle : public Shape
{
private:
	int cx;
	int cy;
	int radius;

	void serializeCX(std::ostream&) const;
	void serializeCY(std::ostream&) const;
	void serializeRadius(std::ostream&) const;

public:

	static const char* TYPENAME;

	Circle();

	Circle(char const*, int, int, int);

	Circle(Circle const&);

	Circle& operator=(Circle const&);

	virtual ~Circle();

	int getCX() const;

	int getCY() const;

	int getRadius() const;

	bool pointIsInside(int, int) const;

	virtual bool IsWithin(Rectangle const&) const;

	virtual bool IsWithin(Circle const&) const;

	virtual void Translate(int, int);

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool serialize(std::ostream&) const;

	virtual bool deserialize(std::istream&);

	virtual char const* getType() const {
		return TYPENAME;
	}

	void setKeyValuePair(std::string, std::string);
};