#include <iostream>
#include <string>
#include <list>

using namespace std;

class IFile
{
public :
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;

	virtual void display() = 0;
	virtual list<IFile *>* getChild() = 0;
};


class File : public IFile
{
public :
	File(string name)
	{
		m_list = NULL;
		m_name = "";
		m_name = name;
	}
	
	~File()
	{
		if (m_list != NULL)
		{
			delete m_list;
		}
	} 
	
	virtual void display()
	{
		cout << m_name << endl;
	}

	virtual int add(IFile *ifile)
	{
		return -1;
	} 
	
	virtual int remove(IFile *ifile)
	{
		return -1;
	} 
	
	virtual list<IFile *>* getChild()
	{
		return NULL;
	}


private:
	list<IFile *> *m_list;
	string m_name;
};


class Folder : public IFile
{
public :
	Folder(string name)
	{
		m_name = name;
		m_list = new list<IFile *>;
	}
	
	~Folder()
	{
		if (m_list == NULL)
		{
			delete m_list;
		}
	}
	
	virtual void display()
	{
		cout << m_name << endl;
	} 
	
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	} 
	
	virtual int remove(IFile *ifile)

	{
		m_list->remove(ifile);
		return 0;
	} 
	
	virtual list<IFile *>* getChild()
	{
		return m_list;
	}

private:
	list<IFile *> *m_list;
	string m_name;
};

void showTree(IFile *ifile, int level)
{
	list<IFile *> *l = NULL;
	int i = 0;
	for (i = 0; i<level; i++)
	{
		printf("\t");
	} 
	
	ifile->display();
	l = ifile->getChild();

	if (l != NULL)
	{
		for (list<IFile *>::iterator it = l->begin(); it != l->end(); it++)
		{
			if ((*it)->getChild() == NULL)
			{
				for (i = 0; i <= level; i++) 
				{
					printf("\t");
				} 
				(*it)->display();
			}  
            else 
            {
				showTree((*it), level + 1); //watch out here
			}
		}
	}
} 


int main(void)
{

	Folder *root = new Folder("C:");
	Folder *dir1 = new Folder("dir1");
	Folder *dir2 = new Folder("dir2");
	File *txt1 = new File("111.txt");
	File *txt2 = new File("222.txt");

	root->display();
	root->add(dir1);
	root->add(txt1);

	dir1->add(dir2);
	dir1->add(txt2);


	cout << "show trees recursively" << endl;
	showTree(root, 0);


	delete txt2;
	delete dir2;
	delete dir1;
	delete txt1;
	delete root;
    system("pause");
    return 0;
}