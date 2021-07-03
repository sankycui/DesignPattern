#include <iostream>
#include <string>
#include <map>

using namespace std;

class Person
{
public :
	Person(string name, int age, int sex)
	{
		this->name = name;
		this->age = age;
		this->sex = sex;
	} 
	
	string getName()
	{
		return name;
	} 
	
	int getAge()
	{
		return age;
	} 
	
	int getSex()
	{
		return sex;
	}

protected:
	string name;
	int age;
	int sex; //1 男 2 女
};

class Teacher : public Person
{
public :
	Teacher(string id, string name, int age, int sex) : Person(name, age, sex)
	{
		this->id = id;
	} 
	string getId()
	{
		return id;
	}

	void printT()
	{
		cout << "id:" << id << "\t" << "name:" << name << "\t" << "age:" << age << "\t" << "sex:"
			<< sex << "\t" << endl;
	}
private:
	string id;
};

class TeacherFactory
{
public :
	TeacherFactory()
	{
		m_tpool.empty();
	} 
	
	~TeacherFactory()
	{

		while (!m_tpool.empty()) 
		{
			Teacher *tmp = NULL;
			map<string, Teacher *>::iterator it = m_tpool.begin();
			tmp = it->second;
			m_tpool.erase(it);
			delete tmp;
		}
	} 
	
	Teacher *getTeacher(string tid)
	{
		string name;
		int age;
		int sex;
		Teacher *tmp = NULL;
		map<string, Teacher*>::iterator it = m_tpool.find(tid);
		if (it == m_tpool.end())
		{
			cout << "id 为: " << tid << " 的老师不存在,系统为你创建该老师， 请输入以下信息" <<endl;	
			cout << "请输入老师姓名： ";
			cin >> name;
			cout << "请输入老师年龄： ";
			cin >> age;
			cout << "请输入老师性别 1 男 2 女： ";
			cin >> sex;

			tmp = new Teacher(tid, name, age, sex);
			m_tpool.insert(pair<string, Teacher*>(tid, tmp));
		} 
		else
		{ //already exist
			tmp = (it->second);
		}
		return tmp;
	}
private:
	map<string, Teacher *> m_tpool;
};


int main()
{

	/*
	Teacher *t1 = new Teacher("001", "小李", 30, 1);
	Teacher *t2 = new Teacher("002", "小张", 30, 1);
	Teacher *t3 = new Teacher("001", "小李", 30, 1);
	Teacher *t4 = new Teacher("004", "小吴", 30, 1);
	//
	cout << "t1 t3 的 工号一样， 但是也不是同一个人 " << endl;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	*/
	TeacherFactory *teacherFactory = new TeacherFactory;
	Teacher *t1 = teacherFactory->getTeacher("001");
	t1->printT();

	/*已经存在的对象直接引用*/
	Teacher *t2 = teacherFactory->getTeacher("001");
	t2->printT();


	delete teacherFactory;

    system("pause");
    return 0;
}