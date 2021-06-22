#include <iostream>

using namespace std;

class Current18v
{
public :
	 virtual void use18vCurrent()
	{
		cout << "use 18v alternating current" << endl;
	}
};


class Current220v
{
public :
	void use220vCurrent()
	{
		cout << "use 220v alternating current" << endl;
	}

};


class Adapter : public Current18v
{
public :
	Adapter(Current220v *p220v)
	{
		m_p220v = p220v;
	}
	
	virtual void use18vCurrent()
	{
		cout << "with adapter, "<< endl;
		m_p220v->use220vCurrent();
	}

private:
	Current220v *m_p220v;
};


int main(void)
{
	Current220v *p220v = new Current220v;

	Current18v *padapter = new Adapter(p220v);
	padapter->use18vCurrent();


	delete p220v;
	delete padapter;
    
    system("pause");
    return 0;
}