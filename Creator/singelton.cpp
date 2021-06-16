#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

/*懒汉式(直到需要创建该类的实例时才进行初始化)*/
class Singelton
{
private:
	static Singelton *m_singer;
	static int m_count;

	Singelton()
	{
		m_singer = NULL;
		m_count = 0;
		cout << "constructor Singelton " << endl;
	}
	~Singelton() {}

    Singelton(const Singelton& obj) {}
    Singelton& operate(const Singelton& obj) {}


public:
	static Singelton *getInstance()
	{
		//懒汉式： 1 每次获取实例都要判断 2 多线程会有问题
		if (m_singer == NULL) 
		{
			m_singer = new Singelton();
		}
		
		return m_singer;
	} 
	
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

};

Singelton *Singelton::m_singer = NULL; /*懒汉式 并没有创建单例对象*/
int Singelton::m_count = 0;

int main()
{
	cout << "Main Function Begin" << endl;


	Singelton *p1 = Singelton::getInstance();
	Singelton *p2 = Singelton::getInstance();
	
	if (p1 != p2)
	{
		cout << "they are not the same thing" << endl;
		
	} else {
		cout << "using the same obj" << endl;
	} 
	
	p1->printT();
	p2->printT();

	cout << "Main Function End" << endl;

    system("pause");

    return 0;
}
