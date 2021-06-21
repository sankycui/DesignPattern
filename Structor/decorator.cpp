/*装饰者模式*/

#include <iostream>
using namespace std;


class Car
{
public :
	virtual void show() = 0;

};

/*原始对象类*/
class RunCar : public Car
{
public :
	void run()
	{
		cout << "run car" << endl;
	}
	virtual void show()
	{
		run();
	}
};

/*继承Car的原因是保持接口的一致*/
class SwimCarDirector : public Car
{
public :
	SwimCarDirector(Car *p)
	{
		m_p = p;
	}

	/*保持接口一致; 并在原来的接口里扩充了方法*/
	virtual void show()
	{
		m_p->show();
		swim();
	}
private:
	Car *m_p;

private:
	/*增加了一个新的接口*/
	void swim()
	{
		cout << "can swim" << endl;
	}
};


class FlyCarDirector : public Car
{
public :
	FlyCarDirector(Car *p)
	{
		m_p = p;
	} 

	virtual void show()
	{
		m_p->show();
		fly();
	}

private:
	Car *m_p;

	/*功能增强*/
	void fly()
	{
		cout << "can fly" << endl;
	}
};



int main(void)
{
	Car *runcar = NULL;
	runcar = new RunCar;
	runcar->show();

	cout << "---------" << endl;
	Car *swimCar = new SwimCarDirector(runcar);
	swimCar->show();


	cout << "---------" << endl;
	Car *flyCar = new FlyCarDirector(swimCar); //watch out
	flyCar->show();

	delete flyCar;
	delete swimCar;
	delete runcar;



    system("pause");
    return 0;
}