#ifndef SERIALIZABLE_H_
#define SERIALIZABLE_H_

#include <iostream>

class Serializable {
public:
	virtual bool serialize(std::ostream&) const = 0;
	virtual bool deserialize(std::istream&) = 0;

	virtual char const* getType() const = 0;

	virtual ~Serializable() {}
};



#endif /* SERIALIZABLE_H_ */