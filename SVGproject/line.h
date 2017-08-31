#include "shape.h"

const char KEY_X1_COORD[] = "x1";
const char KEY_Y1_COORD[] = "y1";
const char KEY_X2_COORD[] = "x2";
const char KEY_Y2_COORD[] = "y2";

class Line : public Shape
{
private:
	int x1;
	int y1;

	int x2;
	int y2;

	void serializeX1(std::ostream&) const;
	void serializeY1(std::ostream&) const;
	void serializeX2(std::ostream&) const;
	void serializeY2(std::ostream&) const;
public:
	static const char* TYPENAME;

	Line();

	Line(char const*, int, int, int, int);

	Line(Line const&);

	Line& operator=(Line const&);

	virtual ~Line();

	int getX1() const { return x1; }

	int getY1() const { return y1; }

	int getX2() const { return x2; }

	int getY2() const { return y2; }

	virtual bool IsWithin(Rectangle const&) const;

	virtual bool IsWithin(Circle const&) const;

	virtual void Translate(int, int);

	virtual void print(std::ostream& os = std::cout) const;

	virtual bool serialize(std::ostream&) const;

	virtual bool deserialize(std::istream&);

	virtual char const* getType() const {
		return TYPENAME;
	}

	void setKeyValuePair(std::string key, std::string value);
};