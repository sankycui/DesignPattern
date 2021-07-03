#include <iostream>

using namespace std;

class SystemA
{
public :
	void doThing()
	{
		cout << "SystemA do...." << endl;
	}
};

class SystemB
{
public :
	void doThing()
	{
		cout << "SystemB do...." << endl;
	}
};

class SystemC
{
public :
	void doThing()
	{
		cout << "SystemC do...." << endl;
	}
};

class Facade
{
public :
	Facade()
	{
		a = new SystemA;
		b = new SystemB;
		c = new SystemC;
	} 
	
	~Facade()
	{
		delete a;
		delete b;
		delete c;
	} 
	
	void doThing()
	{
		a->doThing();
		b->doThing();
		c->doThing();
	}

private:
	SystemA *a;
	SystemB *b;
	SystemC *c;
};


int main()
{

	Facade *f = new Facade;
	f->doThing();
	delete f;

    system("pause");
    return 0;
}