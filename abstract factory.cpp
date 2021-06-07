/*抽象工厂模式*/
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

class Fruit
{
	public :
	virtual void getName()
	{
		cout << "fruit\n";
	}
};


//南方香蕉
class SouthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Banana " << endl;
	}
};


/*南方苹果*/
class SouthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "South Apple " << endl;

	}
};


/*北方香蕉*/
class NorthBanana : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Banana " << endl;
	}
};


/*北方苹果*/
class NorthApple : public Fruit
{
	public :
	virtual void getName()
	{
		cout << "North Apple " << endl;
	}
};


/*抽象工厂*/
class FruitFactory
{
	public :
	virtual Fruit* getApple() = 0;
    virtual Fruit* getBanana() = 0;
};

/*具体的工厂*/
class NothFruitFactory : public FruitFactory
{
	public :
	virtual Fruit* getApple()
    {
        return new NorthApple();
    }

    virtual Fruit* getBanana()
    {
        return new NorthBanana();
    }
};


class SouthFruitFactory : public FruitFactory
{
	public :
	virtual Fruit* getApple()
    {
        return new SouthApple();
    }

    virtual Fruit* getBanana()
    {
        return new SouthBanana();
    }
};



int main()
{
	
    Fruit * fruit = nullptr;
    FruitFactory *fruitFac = nullptr;

    fruitFac = new NothFruitFactory();
    fruit = fruitFac->getApple();
    fruit->getName();
    delete fruit;
    fruit = nullptr;

    fruit = fruitFac->getBanana();
    fruit->getName();
    delete fruit;
    fruit = nullptr;

    delete fruitFac;
    fruitFac = nullptr;


    fruitFac = new SouthFruitFactory();
    fruit = fruitFac->getApple();
    fruit->getName();
    delete fruit;
    fruit = nullptr;

    fruit = fruitFac->getBanana();
    fruit->getName();
    delete fruit;
    fruit = nullptr;

    delete fruitFac;
    fruitFac = nullptr;



    system("pause");
    return 0;
}