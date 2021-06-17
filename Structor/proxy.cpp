/*代理模式*/
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;


class Interface
{
public :
	virtual void Request() = 0;
};

class RealClass : public Interface
{
	public :
		virtual void Request()
		{
			cout << "real request" << endl;
		}
};


class ProxyClass : public Interface
{
private :
	RealClass* m_realClass;
public:
	virtual void Request()
	{
		cout << "proxy request" << endl;
		m_realClass = new RealClass();
		m_realClass->Request();
		delete m_realClass;
	}
};



int main()
{
	cout << "--Main Function Start--" << endl;
	ProxyClass* test = new ProxyClass();
	test->Request();
	cout << "--Main Function End--" << endl;



    system("pause");
    return 0;
}