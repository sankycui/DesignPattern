/*建造者模式*/
#include <iostream>
#include <cstring>
#include <memory>
using namespace std;


#include <iostream>
#include <string>

using namespace std;

class House
{
	public:

	void setFloor(string floor)
	{
		this->m_floor = floor;
	} 
	
	void setWall(string wall)
	{
		this->m_wall = wall;
	} 
	
	void setDoor(string door)
	{
		this->m_door = door;
	}

	string getFloor()
	{
		return m_floor;
	}

	string setWall()
	{
		return m_wall;
	} 
	
	string setDoor()
	{
		return m_door;
	}

private:
	string m_floor;
	string m_wall;
	string m_door;
};

class Builder
{
	public:
	virtual void makeFloor() = 0;
	virtual void makeWall() = 0;
	virtual void makeDoor() = 0;


	virtual House *GetHouse() = 0;  /*相当于组装好了*/
};

class FlatBuild : public Builder
{
	public:
	FlatBuild()
	{
		pHouse = new House;
	}

	virtual void makeFloor()
	{
		pHouse->setFloor("flat Door");
	} 
	
	virtual void makeWall()
	{
		pHouse->setWall("flat Wall");
	} 
	
	virtual void makeDoor()
	{
		pHouse->setDoor("flat Door");
	} 
	
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House *pHouse;
};

class VillaBuild : public Builder
{
	public:
	VillaBuild()
	{
		pHouse = new House;
	}

	virtual void makeFloor()
	{
		pHouse->setFloor("villa floor");
	} 
	
	virtual void makeWall()
	{
		pHouse->setWall("villa Wall");
	} 
	
	virtual void makeDoor()
	{
		pHouse->setDoor("villa Door");
	} 
	
	virtual House *GetHouse()
	{
		return pHouse;
	}
private:
	House *pHouse;
};

class Director
{
	public:
	void Construct(Builder *builder)
	{
		builder->makeFloor();
		builder->makeWall();
		builder->makeDoor();
	}

};


int main(void)
{
#if 0
	/*直接使用builder的情况, 相关构建过程全部暴露*/
	Builder *builder = new FlatBuild;
	builder->makeFloor();
	builder->makeWall();
	builder->makeDoor();
	/*利用builder进行产品的组装*/
	House *house = builder->GetHouse();
	cout << house->getFloor() << endl;
#endif

	/*用生成器director使用Builder进行产品的创建和组装*/

	Director *director = new Director;

	Builder *builder = new FlatBuild;
	director->Construct(builder);
	House *house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;


	builder = new VillaBuild;
	director->Construct(builder); 
	house = builder->GetHouse();
	cout << house->getFloor() << endl;
	delete house;
	delete builder;

	delete director;


    system("pause");
    return 0;
}