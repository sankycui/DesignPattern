#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

/*恶汉式(不管是否创建实例, 都要进行初始化)*/
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
		// if (m_singer == NULL) 
		// {
		// 	m_singer = new Singelton();
		// }
		
		return m_singer;
	} 

    static void releaseInstance()
	{
		/*避免重析构*/
		if (m_singer != NULL) 
		{
			delete m_singer;
			m_singer = NULL;
			m_count = 0;
		}
		else {
			cout << "already released." << endl;
		}
	} 
	
	static void printT()
	{
		cout << "m_count: " << m_count << endl;
	}

};

Singelton *Singelton::m_singer = new Singelton();
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


    Singelton::releaseInstance();
	
	Singelton::releaseInstance(); //already released

	cout << "Main Function End" << endl;

    system("pause");

    return 0;
}
