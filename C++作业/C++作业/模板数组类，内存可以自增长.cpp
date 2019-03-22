//4 .模板数组类，内存可以自增长
#include <iostream>

using namespace std;

template<typename TYPE>
class Array
{
public:
	explicit Array(int sz = DefaultArraySize)
	{
		init(0, sz);
	}
	Array(const TYPE *ar, int sz)
	{
		init(ar, sz);
	}
	Array(const Array<TYPE> &iA)
	{
		init(iA._ia, iA._size);
	}
	~Array();
	Array<TYPE>& operator=(const Array<TYPE> &rhs);
	int size()const;

	TYPE& operator[](int ix)const;
	void grow();
	void sort(int first, int last);
	int find(TYPE &value);
	TYPE min();
	TYPE max();
private:
	void init(const TYPE* arr, int size);
	static const int DefaultArraySize = 12;
	int _size;
	TYPE *_ia;
};

template<typename TYPE>
void Array<typename TYPE>::init(const TYPE* arr, int size)
{
	_ia = new TYPE[size];

	if (arr == nullptr)
	{
		_size = 0;
	}
	else
	{
		_size = size;

		for (int i = 0; i < _size; i++)
		{
			_ia[i] = arr[i];
		}
	}
}

template<typename TYPE>
Array<TYPE>::~Array()
{
	delete _ia;
}

template<typename TYPE>
Array<TYPE>& Array<TYPE>::operator=(const Array<TYPE> &rhs)
{
	if (&rhs != this)
	{
		Array(&rhs);
	}

	return *this;
}

template<typename TYPE>
int Array<TYPE>::size()const
{
	return _size;
}

template<typename TYPE>
TYPE& Array<TYPE>::operator[](int ix)const
{
	try
	{
		if (ix < 0 || ix >= _size)
		{
			throw "";
		}
	}
	catch (...)
	{
		cout << "参数不正确" << endl;
		int tmp = TYPE();
		return tmp;
	}

	return _ia[ix];
}

template<typename TYPE>
void Array<TYPE>::grow()
{

}

template<typename TYPE>
void Array<TYPE>::sort(int first, int last)
{
	if (first < 0 || last < 0 || last > _size || first > _size || first > _size)
	{
		return;
	}

	for (int i = 0; i < last - first; i++)
	{
		for (int j = first; j < last - first - i; j++)
		{
			if (_ia[j] > _ia[j + 1])
			{
				TYPE tmp = _ia[j];
				_ia[j] = _ia[j + 1];
				_ia[j + 1] = tmp;

			}
		}
	}
}
template<typename TYPE>
int Array<TYPE>::find(TYPE &value)
{
	int i = 0;

	for (; i < _size; i++)
	{
		if (_ia[i] == value)
		{
			break;
		}
	}

	if (i == _size)
	{
		return -1;
	}

	return i;
}

template<typename TYPE>
TYPE Array<TYPE>::min()
{
	int min = _ia[0];

	for (int i = 0; i < _size; i++)
	{
		if (min > _ia[i])
		{
			min = _ia[i];
		}
	}

	return min;
}

template<typename TYPE>
TYPE Array<TYPE>::max()
{
	int max = _ia[0];
	for (int i = 0; i < _size; i++)
	{
		if (max < _ia[i])
		{
			max = _ia[i];
		}
	}

	return max;
}

int main()
{
	int arr[] = { 1, 3, 8, 4, 5};

	//cout << arr1[8] << endl;

	int val = 13;

	int a = arr2.find(val);

	arr2.sort(1, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << arr2[i] << endl;
	}
 
	cout << arr2.max() << endl;
	cout << arr2.min() << endl;

	return 0;
}