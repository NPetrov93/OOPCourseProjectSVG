#include "shape.h"

const char KEY_X_COORD[] = "x";
const char KEY_Y_COORD[] = "y";
const char KEY_WIDTH[] = "width";
const char KEY_HEIGHT[] = "height";

class Rectangle : public Shape
{
private:
	int x;
	int y;
	int width;
	int height;

	void serializeX(std::ostream&) const;
	void serializeY(std::ostream&) const;
	void serializeWidth(std::ostream&) const;
	void serializeHeight(std::ostream&) const;

public:
	static const char* TYPENAME;

	Rectangle();

	Rectangle(char const*, int, int, int, int);

	Rectangle(Rectangle const&);

	Rectangle& operator=(Rectangle const&);

	virtual ~Rectangle();

	int getX() const;

	int getY() const;

	int getWidth() const;

	int getHeight() const;

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