#include <iostream>

using namespace std;

template<typename ContainerIterator>
class reverse_iterator
{
public:
	reverse_iterator(ContainerIterator &it) :_it(it){}
	bool operator!=(const reverse_iterator<ContainerIterator> &src);
	void operator++();
	T& operator*();
	const T& operator*()const;
	T* operator->()
	{
		return _it;
	}
	const T* operator->()const
	{
		return _it;
	}
private:
	ContainerIterator _it;
};

template<typename T>
class CVector
{
public:
	class iterator;
	typedef reverse_iterator<iterator> reverse_iterator;

	CVector()
	{
		_pvec = new T[10];
		_size = 10;
		_index = 0;
	}
	CVector(int initSize, T defaultValue = T())
	{
		_pvec = new T[initSize];
		_size = initSize;
		_index = 0;
		for (int i = 0; i<_size; ++i)
		{
			_pvec[_index++] = defaultValue;
		}
	}
	CVector(T *first, T *last)
	{
		_size = last - first;
		_pvec = new T[_size];
		for (; first != last; ++first)
		{
			_pvec[_index++] = *first;
		}
	}
	void push_back(const T &val)
	{
		if (full())
			resize();
		_pvec[_index++] = val;
	}
	void resize()
	{
		_size *= 2;
		T *ptmp = new T[_size];
		memcpy(ptmp, _pvec, sizeof(T)*_index);
		delete[]_pvec;
		_pvec = ptmp;
	}
	void pop_back()
	{
		if (empty())
			return;
		--_index;
	}
	T back()const{ return _pvec[_index - 1]; }
	bool full()const{ return _index == _size; }
	bool empty()const{ return _index == 0; }
	int size()const{ return _index; }
	T& operator[](int index){ return _pvec[index]; }
	const T& operator[](int index)const{ return _pvec[index]; }

	class iterator
	{
	public:
		iterator(T *ptr) :_ptr(ptr){}
		bool operator!=(const iterator &src)
		{
			return _ptr != src._ptr;
		}
		void operator++()
		{
			++_ptr;
		}
		T& operator*(){ return *_ptr; }
		const T& operator*()const{ return *_ptr; }
	private:
		T *_ptr;
	};


	iterator begin()
	{
		return iterator(_pvec);
	}
	iterator end()
	{
		return iterator(_pvec + _index);
	}
	reverse_iterator rbegin()
	{
		return iterator(_pvec + _index);
	}
	reverse_iterator rend()
	{
		return iterator(_pvec);
	}
	T* operator->(){ return mptr; }

private:
	T *_pvec;
	int _size;
	int _index;
	friend ostream& operator<<<T>(ostream&, const CVector<T>&);
};
template<typename T>
ostream& operator<<(ostream &out, const CVector<T> &vec)
{
	for (int i = 0; i<vec._index; ++i)
	{
		out << "vec[" << i << "]=" << vec[i] << endl;
	}
	out << endl;
	return out;
}
/////////////////////////////////////////////

int main()
{
	CVector<int> vec1(10, 89);

	for (int i = 0; i<12; ++i)
	{
		vec1.push_back(rand() % 100 + 1);
	}

	/************************************************************************/
	/*
	const CVector<int>::iterator it1 = vec1.begin();
	CVector<int>::const_iterator it1 = vec1.begin();
	*/
	/************************************************************************/
	CVector<int>::iterator it1 = vec1.begin();
	for (; it1 != vec1.end(); ++it1)
	{
		cout << *it1 << " ";
	}
	cout << endl;

	CVector<int>::reverse_iterator rit = vec1.rbegin();
	for (; rit != vec1.rend(); ++rit)
	{
		cout << *rit << " ";
	}

	// 	cout<<"------------------------------"<<endl;
	// 	string str = "lllllllllllllllddddddddddddiiiiiiiii";
	// 	string::reverse_iterator it2 = str.rbegin();
	// 	for(; it2 != str.rend(); ++it2)
	// 	{
	// 		cout<<*it2<<" ";
	// 	}

	return 0;
}