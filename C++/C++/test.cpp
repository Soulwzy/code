#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
智能指针


int *p   裸指针
*/
class Test
{
public:
	void func(){}
private:
};

class CCountTable
{
private:
	CCountTable(){}
	struct Node
	{
		void *mheapPtr;
		int mcount;

		Node(void *ptr)
		{
			mheapPtr = ptr;
			mcount = 1;
			cout << "新添加" << ptr << endl;
		}
	};

	vector<Node> nodeVec;

public:
	static CCountTable* getInstance()
	{
		static CCountTable c;

		return &c;
	}
	void addRef(void *ptr)
	{
		vector<Node>::iterator it;
		for (it = nodeVec.begin(); it != nodeVec.end(); it++)
		{
			if (it->mheapPtr == ptr)
			{
				it->mcount++;
				break;
			}
		}

		if (it == nodeVec.end())
		{
			Node node(ptr);
			nodeVec.push_back(node);
		}

		//	cout << ptr << "添加" << endl;
	}
	void delRef(void *ptr)
	{
		vector<Node>::iterator it;
		for (it = nodeVec.begin(); it != nodeVec.end(); it++)
		{
			if (it->mheapPtr == ptr)
			{
				it->mcount--;
				cout << ptr << "释放" << endl;
				break;
			}
		}

		if (it == nodeVec.end())
		{
			//nodeVec.erase(nodeVec.begin() + 2)
			cout << "error" << endl;
		}


	}
	int getRef(void *ptr)
	{
		vector<Node>::iterator it;
		for (it = nodeVec.begin(); it != nodeVec.end(); it++)
		{
			if (it->mheapPtr = ptr)
			{
				return it->mcount;
			}
		}

		return -1;
	}
};

//带有引用计数的智能指针
template<typename T>
class CSmartPtr
{
public:
	CSmartPtr(T *ptr = NULL) :mptr(ptr)
	{
		if (mptr != NULL)
			addRef();
	}
	CSmartPtr(const CSmartPtr<T> &src) :mptr(src.mptr)
	{
		if (mptr != NULL)
			addRef();
	}
	CSmartPtr<T>& operator=(const CSmartPtr<T> &src)
	{
		if (this == &src)
			return *this;

		delRef();
		if (0 == getRef())
			delete mptr;

		mptr = src.mptr;
		if (mptr != NULL)
			addRef();
		return *this;
	}
	T* operator ->()
	{
		return mptr;
	}
	~CSmartPtr()
	{
		delRef();
		if (0 == getRef())
		{
			cout << "11111" << endl;
			delete mptr;
		}
	}
	void addRef(){ mTable->addRef(mptr); }
	void delRef(){ mTable->delRef(mptr); }
	int getRef(){ return mTable->getRef(mptr); }
private:
	T *mptr;
	static CCountTable* mTable;
};
template<typename T>
CCountTable* CSmartPtr<T>::mTable = CCountTable::getInstance();

//int main()
//{
//	// 	CSmartPtr<int> pointer1(new int);
//	// 	*pointer1 = 100;
//	// 
//	// 	CSmartPtr<Test> pointer2(new Test);
//	// 	pointer2->func();
//	// 
//	// 	CSmartPtr<int> pointer3(pointer1);
//	// 	pointer3 = pointer1;
//
//	//CSmartPtr<int> pointer1(new int);
//	//CSmartPtr<int> pointer2(pointer1);
//	//CSmartPtr<int> pointer3;
//	//cout << "----------" << endl;
//	//pointer3 = pointer2;
//	//cout << "----------" << endl;
//	//CSmartPtr<int> pointer4(new int);
//	//CSmartPtr<int> pointer5(pointer4);
//	//pointer3 = pointer4;
//
//	int *p = new int;
//	CSmartPtr<int> pointer1(p);
//	CSmartPtr<char> pointer2((char*)p);
//
//	return 0;
//}

class B;
class A
{
public:
	A(){ cout << "A()" << endl; }
	~A(){ cout << "~A()" << endl; }
	weak_ptr<B> _ptrB;
};
class B
{
public:
	B(){ cout << "B()" << endl; }
	~B(){ cout << "~B()" << endl; }
	CSmartPtr<A> _ptrA;
};

int main()
{
	CSmartPtr<A> pa(new A());
	CSmartPtr<B> pb(new B());

	pa->_ptrB = pb;
	pb->_ptrA = pa;
}