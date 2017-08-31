#ifndef SVG_SERIALIZABLE_H_
#define SVG_SERIALIZABLE_H_

#include "serializable.h"

class SVGSerializable : public Serializable {
private:
	std::string deserializeKey(std::istream&) const;
	std::string deserializeValue(std::istream&) const;
public:

	void startSerialize(std::ostream&) const;
	void finishSerialize(std::ostream&) const;

	void serializeString(std::ostream&, char const*) const;
	void serializeInt(std::ostream&, int) const;
	void serializeKey(std::ostream&, char const*) const;
	void serializeKeyIntValue(std::ostream&,
		char const*, int) const;
	void serializeKeyStringValue(std::ostream&,
		char const*, char const*) const;

	void serializeType(std::ostream&) const;

	bool deserializeKeyValuePair(std::istream&, std::string&, std::string&);
};



#endif /* SVG_SERIALIZABLE_H_ */