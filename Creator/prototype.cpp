// Prototype.cpp : 定义控制台应用程序的入口点。
//

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
public:
	virtual Person *Clone() = 0;
	virtual void printT() = 0;
	virtual ~Person() 
	{
		cout << "deconstructor of Person" << endl;
	}
};

class JavaProgrammer : public Person
{
public :
	JavaProgrammer()
	{
		this->m_name = "";
		this->m_age = 0;
		m_resume = NULL;
	} 

    JavaProgrammer &operator=(const JavaProgrammer &jp) //深拷贝
	{
		this->m_name = jp.m_name;
		this->m_age = jp.m_age;
		this->m_resume = new char[strlen(jp.m_resume) + 1];
		strcpy(m_resume, jp.m_resume);

        return *this;
	}
		
	JavaProgrammer(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
		m_resume = NULL;
	} 
	
	~JavaProgrammer()
	{
		if (m_resume != NULL)
		{
			free(m_resume);
			m_resume = NULL;
		}
	} 
	
	void setResume(char *resume)
	{
		m_resume = new char[strlen(resume) + 1];
		strcpy(m_resume, resume);
	}

	virtual Person *Clone()
	{
		JavaProgrammer *p = new JavaProgrammer;
		*p = *this;
		return p;
	} 
	
    virtual void printT()
	{
		cout << "m_name:" << m_name.c_str() << "\t" << "m_age:" << m_age << "\t";
		if (m_resume != NULL)
		{
			cout << m_resume << endl;
		}
	}

private:
	string m_name;
	int m_age;
	char *m_resume;  /*用来测试深浅拷贝*/
};

int main(void)
{

	JavaProgrammer j1("tom", 30);
	j1.setResume("java programmer");
	j1.printT();

	Person *p2 = j1.Clone();
	p2->printT();

	delete p2;

	j1.printT(); //m_resume是乱码

    system("pause");

    return 0;
}