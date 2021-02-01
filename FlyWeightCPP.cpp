/*
 * C++ Design Patterns: Flyweight
 * Author: Mahsa Hassankashi [github.com/Hassankashi]
 * 2021
 *
 * Source code is licensed under MIT License
 * (for more details see LICENSE)
 *
 */

#include <iostream>
#include <map>
#include <string>
#include <list>
#include <unordered_map>

class Person
{
public:
	virtual ~Person() {}
	virtual void createVisitCard() = 0;
};


class Employee : public Person
{
public:
	Employee(std::string name) :
		state(name) {}

	~Employee() {}

	void createVisitCard()
	{
		std::cout << "Employee: createVisitCard() [Name : " + state + ", Phone : " + setPhone() + ", Address :" + setAddress() + "]" << std::endl;
	}
	std::string setPhone() {
		return "9090";
	}
	std::string setAddress() {
		return "ABC";
	}
private:
	std::string state;
};

class PersonFactory
{
public:
	~PersonFactory()
	{
		for (auto it = flies.begin(); it != flies.end(); it++)
		{
			delete it->second;
		}
		flies.clear();
	}
	Person *getEmployee(std::string name)
	{
		if (flies.find(name) != flies.end())
		{
			return flies[name];
		}
		Person* flyobject = new Employee(name);
		flies.insert(std::pair<std::string, Person*>(name, flyobject));
		return flyobject;
	}

private:
	std::map<std::string, Person*> flies;
};

int main()
{
	
	PersonFactory* factory = new PersonFactory;
	factory->getEmployee("Mahsa")->createVisitCard();
	factory->getEmployee("Hassankashi")->createVisitCard();
	delete factory;
	return 0;
}
