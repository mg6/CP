// Copyright 2014 mg6
// Released under the terms of GNU GPL v2 license

#include <iostream>

namespace Zoo
{
	enum Food
	{
		FOOD_ANY = 0,
		FOOD_FISH,
		FOOD_FEED
	};

	class Animal
	{
	public:
		Animal()
		{
			std::cout << ">> Animal created" << std::endl;
		}

		~Animal()
		{
			std::cout << "<< Animal destroyed" << std::endl;
		}

		void eat(Food f)
		{
			if (f != getFoodType())
				std::cout << "Animal does not like food " << getFoodType() << "." << std::endl;
			else
				std::cout << "Eating yummy food of type " << getFoodType() << "." << std::endl;
		}

		void sleep()
		{
			std::cout << "An animal is sleeping." << std::endl;
		}

	private:
		Food getFoodType()
		{
			return FOOD_ANY;
		}
	};

	class Dog : public Animal
	{
	public:
		void bark()
		{
			std::cout << "Woof woof!" << std::endl;
		}

		Food getFoodType()
		{
			return FOOD_FEED;
		}
	};

	class GermanShepherd : public Animal
	{
	public:
		void bark()
		{
			std::cout << "WOOF WOOF WOOF!" << std::endl;
		}
	};

	class Dachshund : public Dog
	{
	public:
		Dachshund() : length(0.75f) {}

		float getLength()
		{
			return length;
		}

	private:
		float length;
	};

	class Cat : public Animal
	{
	public:
		void purr()
		{
			std::cout << "Purring..." << std::endl;
		}

		void sleep()
		{
			std::cout << "Falling asleep." << std::endl;
			purr();
		}

		Food getFoodType()
		{
			return FOOD_FISH;
		}
	};

	class Manx : public Cat
	{
	public:
		Food getFoodType()
		{
			return FOOD_FEED;
		}
	};

	class Hybrid : public Cat, public Dog
	{
	public:
		void eat(Food f)
		{
			std::cout << "Eating anything." << std::endl;
		};

		Food getFoodType()
		{
			return FOOD_ANY;
		}
	};
}

int main()
{
	std::cout << "Animal:" << std::endl;
	Zoo::Animal a;
	a.sleep();

	std::cout << std::endl <<  "Cat:" << std::endl;
	Zoo::Cat cat;
	cat.eat(Zoo::FOOD_FISH);
	cat.sleep();

	std::cout << std::endl << "Dachshund:" << std::endl;
	Zoo::Dachshund dog;
	dog.eat(Zoo::FOOD_ANY);
	dog.bark();
	std::cout << "Length of a dachshund is " << dog.getLength() << "." << std::endl;

	std::cout << std::endl << "German Shepherd:" << std::endl;
	Zoo::GermanShepherd ger;
	ger.bark();

	std::cout << std::endl << "Manx:" << std::endl;
	Zoo::Manx manx;
	manx.eat(Zoo::FOOD_FEED);
	manx.sleep();

	std::cout << std::endl << "Hybrid:" << std::endl;
	Zoo::Hybrid hyb;
	hyb.purr();
	hyb.eat(Zoo::FOOD_ANY);
	hyb.bark();

	std::cout << std::endl << "Cleanup..." << std::endl;

	return 0;
}
