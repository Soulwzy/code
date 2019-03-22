//3 . 修改下面代码中的模板语法错误
#include<iostream>
using namespace std;

template<typename ElemType>
class ListItem;

template<typename ElemType>
class List
{
public:
	List<ElemType>() : _at_front(NULL), _at_end(NULL), _current(NULL), _size(0){}
	List<ElemType>(const List<ElemType>& src);
	List<ElemType>& operator=(const List<ElemType>& rhs);
	~List();

	void insert(ListItem *ptr, ElemType value);
	int remove(ElemType value);
	ListItem* find(ElemType value);
	void display(ostream &os = cout);
	int size(){ return _size; }
private:
	ListItem *_at_front;
	ListItem *_at_end;
	ListItem *_current;
	int _size;
};