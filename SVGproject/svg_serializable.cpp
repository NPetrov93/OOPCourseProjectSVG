#include "stdafx.h"
#include <assert.h>     /* assert */
#include "svg_serializable.h"

void SVGSerializable::startSerialize(std::ostream& os) const
{
	os << "<";
}

void SVGSerializable::finishSerialize(std::ostream& os) const
{
	os << "/>\n";
}

void SVGSerializable::serializeString(std::ostream& os, const char* s) const {
	os << '"' << s << '"';
}


void SVGSerializable::serializeInt(std::ostream& os, int n) const {
	os << '"' << n << '"';
}


void SVGSerializable::serializeKey(std::ostream& os, const char* key) const {
	os << key << '=';
}

void SVGSerializable::serializeKeyIntValue(std::ostream& os, const char* key,
	int value) const {
	serializeKey(os, key);
	serializeInt(os, value);
	os << " ";
}

void SVGSerializable::serializeKeyStringValue(std::ostream& os,
	const char* key, const char* value) const {
	serializeKey(os, key);
	serializeString(os, value);
	os << " ";
}

void SVGSerializable::serializeType(std::ostream& os) const {
	os << getType() << ' ';
}

std::string SVGSerializable::deserializeKey(std::istream& is) const
{
	char ch;
	std::string key;
	if (is.eof())
		assert("Erroc. Could not read file properly");
	is >> ch;
	while (ch != '=')
	{
		if (is.eof())
			assert("Erroc. Could not read file properly");
		key.append(1, ch);
		if (key == "/>")
			return key;
		is >> ch;
	}

	return key;
}

std::string SVGSerializable::deserializeValue(std::istream& is) const
{
	char ch = '-';
	std::string value;
	if (is.eof())
		assert("Error. Could not read file properly");
	while (ch != '"')
	{
		if (is.eof())
			assert("Error. Could not read file properly");
		is >> ch;
	}

	is >> ch;

	while (ch != '"')
	{
		if (is.eof())
			assert("Error. Could not read file properly");
		value.append(1, ch);
		is >> ch;
	}

	return value;
}

bool SVGSerializable::deserializeKeyValuePair(std::istream& is, std::string& str_key, std::string& str_value) {
	str_key = deserializeKey(is);
	if (str_key == "/>")
		return false;
	str_value = deserializeValue(is);

	return is.good();
}

/*
const char* keyToReturn = deserializeKey(is);
const char* valueToReturn = deserializeValue(is);

char* key = new char[strlen(keyToReturn) + 1];
char* value = new char[strlen(valueToReturn) + 1];

strcpy_s(key,strlen(keyToReturn) + 1, keyToReturn);
/strcpy_s(value, strlen(valueToReturn) + 1, valueToReturn);

*p_key = key;
*p_value = value;*/