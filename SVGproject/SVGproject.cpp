#include "stdafx.h"
#include <assert.h> /* assert */
#include "svg_factory.h"
#include <string>
#include <fstream>
#include<sstream>
#include <vector>

bool Rectangle::IsWithin(Rectangle const& rect) const
{
	if (x >= rect.x && y >= rect.y && x + height <= rect.x + rect.height && y + width <= rect.y + rect.width)
		return true;

	return false;
}

bool Rectangle::IsWithin(Circle const& circle) const
{
	if (circle.pointIsInside(x, y) && circle.pointIsInside(x, y + height) && circle.pointIsInside(x + width, y) && circle.pointIsInside(x + width, y + height))
		return true;

	return false;
}

bool Circle::IsWithin(Rectangle const& rect) const
{
	return true;
}

bool Circle::IsWithin(Circle const& circle) const
{
	double radiusesDistance = Shape::findDistance(cx, cy, circle.cx, circle.cy);
	if (radiusesDistance + radius <= circle.radius)
		return true;

	return false;
}

bool Line::IsWithin(Rectangle const& rect) const
{
	if (rect.pointIsInside(x1, y1) && rect.pointIsInside(x2, y2))
		return true;

	return false;
}

bool Line::IsWithin(Circle const& circle) const
{
	if (circle.pointIsInside(x1, y1) && circle.pointIsInside(x2, y2))
		return true;

	return false;
}

std::vector<Shape*> vect;

void ReadSVG(std::ifstream& is)
{
	SVG_Factory factory = SVG_Factory();
	char ch;
	std::string textLine;
	std::string shapeType;

	std::getline(is, textLine);
	while (textLine != "<svg>")
	{
		std::getline(is, textLine);
		if (is.eof())
		{
			assert("Something is not right");
			return;
		}
	}

	Shape* shape;

	is >> ch;

	do
	{

		while (ch != '<' && !is.eof())
		{
			is >> ch;
		}

		if (is.eof())
		{
			std::cout << "success" << std::endl;
			return;
		}

		is >> ch;

		while (ch == ' ')
		{
			is.get(ch);
		}

		while (ch != ' ' && !is.eof())
		{
			shapeType.append(1, ch);
			is.get(ch);
		}

		if (is.eof())
		{
			std::cout << "success" << std::endl;
			return;
		}

		Shape* shape = factory.createShape(shapeType);
		if (shape == nullptr)
			break;
		shape->deserialize(is);
		vect.push_back(shape);
		shapeType.clear();
	} while (true);

}

void WriteSVG(std::ofstream& os)
{
	os << "<svg>\n";

	for (size_t i = 0; i < vect.size(); i++)
	{
		vect[i]->serialize(os);
		delete vect[i];
	}

	os << "</svg>\n";

	os.close();
}

int main()
{
	
	std::ofstream osx("shapes.svg");
	osx << "<svg>\n";

	Line* line = new Line("red", 3, 3, 5, 5);
	Rectangle* rect = new Rectangle("green", 5, 5, 10, 10);
	Circle* circle = new Circle("red", 10, 10, 5);

	Shape* shape = line;
	shape->serialize(osx);
	shape = rect;
	shape->serialize(osx);
	shape = circle;
	shape->serialize(osx);
	osx << "</svg>\n";

	osx.close();
	std::string input;
	std::ofstream os;
	std::ifstream is;

	while (true)
	{
		std::getline(std::cin, input);
		if (input == "exit")
			return 0;
		else if (input.substr(0, 4) == "open")
		{
			if (!os.is_open())
			{
				std::string fileName = input.substr(5, input.length() - 5);
				is = std::ifstream(fileName);
				ReadSVG(is);
				os = std::ofstream(fileName);
			}
			else
			{
				std::cout << "There is already an opened file. Please save first." << std::endl;
			}
		}
		else if (input.substr(0, 4) == "save")
		{
			WriteSVG(os);
		}
		else if (input.substr(0, 5) == "print")
		{
			for (size_t i = 0; i < vect.size(); i++)
			{
				std::cout << i << ". ";
				vect[i]->print(std::cout);
				std::cout << std::endl;
			}
		}
		else if (input.substr(0, 5) == "erase")
		{
			std::string substr = input.substr(5, input.length() - 5);
			std::stringstream geek(substr);
			int index = 0;
			geek >> index;
			if (index < vect.size() && index > 0)
			{
				std::cout << "Erase " << vect[index - 1]->getType() << " " << index << std::endl;
				vect.erase(vect.begin() + index - 1);
			}
			else
			{
				std::cout << "No element with index " << index - 1 << std::endl;
			}
		}
		else if (input.substr(0, 9) == "translate")
		{
			std::string str_vertical = input.substr(19, 2);
			std::string str_horizontal = input.substr(33, 2);

			std::stringstream geek(str_vertical);
			int vertical;
			geek >> vertical;
			std::stringstream geek2(str_horizontal);
			int horizontal;
			geek2 >> horizontal;
			for (size_t i = 0; i < vect.size(); i++)
			{
				vect[i]->Translate(vertical, horizontal);
			}
			std::cout << "Translated all figures " << std::endl;
		}
	}


	/*std::ifstream is("shapes.svg");
	if (!is)
		std::cout << "error";

	ReadSVG(is);

	std::ofstream os("shapes.svg");
	WriteSVG(os);*/

	system("pause");
	return 0;
}

