// Copyright 2014 mg6
// Released under the terms of GNU GPL v2 license

#include <iostream>

#define MATH_PI 3.1415926535

class Figure
{
public:
	virtual float area() = 0;

	void report(const char* str)
	{
		std::cout << str << std::endl;
	}
};

class Rectangle : public Figure
{
public:
	Rectangle(float a, float b) : a(a), b(b) { std::cout << "Rectangle created with a=" << a << " b=" << b << std::endl; }
	~Rectangle() { report("Rectangle destroyed."); }

	float area() { return a * b; }

protected:
	float a;
	float b;
};

class Square final : public Rectangle
{
public:
	Square(float a) : Rectangle(a, a) { std::cout << "Square created with a=" << a << std::endl; }
	~Square() { report("Square destroyed."); }
};

class Triangle final : public Figure
{
public:
	Triangle(float a, float h) : a(a), h(h) { std::cout << "Triangle created with a=" << a << " h=" << h << std::endl; }
	~Triangle() { report("Triangle destroyed."); }

	float area() { return a*h / 2; }

private:
	float a;
	float h;
};

class Circle final : public Figure
{
public:
	Circle(float rad) : rad(rad) { std::cout << "Circle created with rad=" << rad << std::endl; }
	~Circle() { report("Circle destroyed."); }

	float area() { return MATH_PI * rad * rad; }

private:
	float rad; // radius
};

int main(int argc, char **argv)
{
	auto rec = Rectangle(3, 2);
	std::cout << "Area=" << rec.area() << std::endl;

	auto sq = Square(5);
	auto *pSq = static_cast<Figure *>(&sq);
	std::cout << "Area=" << pSq->area() << std::endl;

	auto tr = Triangle(10, 5);
	std::cout << "Area=" << tr.area() << std::endl;

	auto cr = Circle(10);
	auto *pCr = static_cast<Figure *>(&cr);
	std::cout << "Area=" << pCr->area() << std::endl;
	system("pause");

	return 0;
}
