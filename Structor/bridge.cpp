#include <iostream>

using namespace std;

class Engine
{
public :
	virtual void installEngine() = 0;
};


class Engine4000 : public Engine
{
public :
	virtual void installEngine()
	{
		cout << "Engine4000" << endl;
	}
};

class Engine3500 : public Engine
{
public :
	virtual void installEngine()
	{
		cout << "Engine 3500" << endl;
	}
};


class Car
{
public :
	Car(Engine *pengine)
	{
		m_engine = pengine;
	}
	virtual void installEngine() = 0;

protected:
	Engine *m_engine;
};


class BMW7 :public Car
{
public :
	BMW7(Engine *p) : Car(p){ } 
	
	virtual void installEngine()
	{
		cout << "BMW7 ";
		m_engine->installEngine();
	}

};


int main()
{
	/*最小类设计, Engine 和 Car的抽象和实现相互隔离, 互补干扰*/
	Engine4000 *e4000 = new Engine4000;
	BMW7 *bmw7 = new BMW7(e4000);
	bmw7->installEngine();

    system("pause");
    return 0;
}