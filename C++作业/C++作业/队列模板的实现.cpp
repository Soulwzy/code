#include <iostream>

using namespace std;

template<typename T>
class Queue
{
public:
	Queue();
	Queue(const Queue<T>& src);
	~Queue();
	Queue<T>& operator=(const Queue<T>& rhs);
	T& remove();
	void add(const T&);
	bool isEmpty();
private:
	class QueueItem
	{
	public:
		QueueItem(const T&);
	public:
		T item;
		QueueItem *next;
	};
private:
	QueueItem *front;
	QueueItem *back;
};

template<typename T>
Queue<T>::Queue(const Queue<T>& src)
{
	front = back = nullptr;
	cout << " afasdf" << endl;
	QueueItem *p = src.front;

	while (p != nullptr)
	{
		add(p->item);
		p = p->next;
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& rhs)
{
	if (&rhs != this)
	{
		front = back = nullptr;
		QueueItem *p = rhs.front;

		while (p != nullptr)
		{
			add(p->item);
			p = p->next;
		}
	}

	return *this;
}

template<typename T>
Queue<T>::Queue()
{
	front = back = nullptr;
}

template<typename T>
Queue<T>::~Queue()
{
	if (isEmpty())
	{
		return;
	}
	else
	{
		QueueItem *p = front;
		
		while (front != nullptr)
		{
			front = front->next;
			delete p;
			p = front;
		}

		front = back = nullptr;
	}
}

template<typename T>
Queue<T>::QueueItem::QueueItem(const T& src)
{
	item = src;
	next = nullptr;
}



template<typename T>
void Queue<T>::add(const T& src)
{
	if (isEmpty())
	{
		front = back = new QueueItem(src);
	}
	else
	{
		QueueItem *p = new QueueItem(src);
		
		back->next = p;
		back = p;
	}
}

template<typename T>
bool Queue<T>::isEmpty()
{
	return front == nullptr;
}

template<typename T>
T& Queue<T>::remove()
{
	if (!isEmpty())
	{
		QueueItem *p = front;
		front = p->next;

		return p->item;
	}
	else
	{
		cout << "©у╤сап" << endl;
		int tmp = T();
		return tmp;
	}
}

//int main()
//{
//	Queue<int> queue;
//
//	for (int i = 0; i < 10; i++)
//	{
//		queue.add(i);
//	}
//
//	Queue<int> queue1(queue);
//
//	Queue<int> queue2 = queue;
//
//
//	for (int i = 0; i < 10; i++)
//	{
//		queue.remove();
//	}
//
//	return 0;
//}

