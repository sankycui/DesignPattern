/*工厂方法模式*/
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Fruit
{
	public:
	virtual void getName() = 0;
};

class Banana : public Fruit
{
	public:
	void getName()
	{
		std::cout<<"banana"<<std::endl;
	}
};

/*下面再扩展一个产品, 那么需要扩展两个东西: 相关产品, 相关工厂*/
class Apple : public Fruit
{
	public:
	virtual void getName()
	{
		cout << "Apple" << endl;
	}
};


/*抽象工厂*/
class FruitFactory
{
	public :
	virtual Fruit* getFruit() = 0;
};

/*具体的工厂*/
class BananaFactory : public FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Banana;
	}
};


class AppleFactory : public FruitFactory
{
	public :
	virtual Fruit* getFruit()
	{
		return new Apple;
	}
};


int main()
{
	FruitFactory *fruitFac;

	fruitFac = new BananaFactory();
	Fruit* fruit  = fruitFac->getFruit();
	if (fruit  == nullptr)
	{
		cout << "创建产品失败\n";
	}
	fruit ->getName();

	delete fruit ;
	delete fruitFac;

	fruitFac = new AppleFactory();
	fruit  = fruitFac->getFruit();
	if (fruit  == nullptr)
	{
		cout << "创建产品失败\n";
	}
	fruit ->getName();


	delete fruit ;
	fruit = NULL;
	delete fruitFac;
	fruitFac = NULL;

    system("pause");
    return 0;
}