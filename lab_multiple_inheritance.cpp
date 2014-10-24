// Copyright 2014 mg6
// Released under the terms of GNU GPL v2 license

#include <iostream>
#include <string>
#include <sstream>

// Multiple inheritance
//
// Let's make a class that inherits: integer variable, double variable,
// function and virtual function from five different classes. Don't
// forget about constructor and destructor.

class Base
{
public:
	Base()
	{
		std::cout << "Base()" << std::endl;
	}

	~Base()
	{
		std::cout << "~Base()" << std::endl;
	}

	virtual const char* name() const
	{
		return "<Base>";
	}

	virtual std::string info()
	{
		return "No info present";
	}

	friend std::ostream& operator<<(std::ostream& o, Base& b)
	{
		return o << b.name() << " " << b.info();
	}
};

struct Point : virtual Base
{
	int x;
	int y;

	Point() : x(5), y(6)
	{
		std::cout << "Point()" << std::endl;
	}

	Point(int x, int y) : x(x), y(y)
	{
		std::cout << "Point()" << std::endl;
	}

	~Point()
	{
		std::cout << "~Point()" << std::endl;
	}

	const char* name() const
	{
		return "<Point>";
	}

	std::string info()
	{
		std::stringstream s;
		s << "x=" << x << " y=" << y;
		return s.str();
	}
};

struct Physics : virtual Base
{
	double mass;

	Physics() : mass(3.2)
	{
		std::cout << "Physics()" << std::endl;
	}

	~Physics()
	{
		std::cout << "~Physics()" << std::endl;
	}

	const char* name() const
	{
		return "<Physics>";
	}

	std::string info()
	{
		std::stringstream s;
		s << "mass=" << mass;
		return s.str();
	}
};

struct MaterialPoint : virtual Base, Point, Physics
{
	Point p;

	MaterialPoint() : p(8, 7)
	{
		std::cout << "MaterialPoint()" << std::endl;
	}

	~MaterialPoint()
	{
		std::cout << "~MaterialPoint()" << std::endl;
	}

	const char* name() const
	{
		return "<MaterialPoint>";
	}

	std::string info()
	{
		std::stringstream s;
		s << Point::info() << " " << p.info() << " " << Physics::info();
		return s.str();
	}
};

int main(int argc, char** argv)
{
	{
		Base b;
		Point p;
		Physics ph;
		MaterialPoint mp;

		std::cout
			<< b << std::endl
			<< p << std::endl
			<< ph << std::endl
			<< mp << std::endl;
	}

	std::cin.get();

	return 0;
}
