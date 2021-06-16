/*简单工厂模式*/
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;

};


class Banana : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "banana" << endl;
	}

};


class Pear : public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "pear" << endl;
	}

};


class Factory
{
public:
	std::shared_ptr<Fruit> Create(char *name)
	{
		std::shared_ptr<Fruit> tmp;
		if (strcmp(name, "pear") == 0)
		{
			tmp = std::make_shared<Pear>();
		} else if (strcmp(name, "banana") == 0)
		{
			tmp = std::make_shared<Banana>();
		} 

		return tmp;
	}
};


int main()
{
	Factory fruitFac;

	std::shared_ptr<Fruit> pear = fruitFac.Create("pear");
	if (pear == nullptr)
	{
		cout << "创建产品失败\n";
	}
	pear->getFruit();
	std::shared_ptr<Fruit> banana = fruitFac.Create("banana");
	banana->getFruit();

    system("pause");
    return 0;
}
