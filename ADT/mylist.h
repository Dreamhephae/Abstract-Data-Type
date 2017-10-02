#ifndef _MYLIST_H_
#define _MYLIST_H_


#include <iostream>

using namespace std;
 

namespace
{
	template<typename ElementType>
	struct _Node
	{
		ElementType Data;
		_Node<ElementType> * pref = NULL;
		_Node<ElementType> * next = NULL;
	};
}


template<typename T>
class List
{
public:

	List();
	~List();

	bool isEmpty();
	_Node<T> * find(const T & n);
	void insert(const T & n,_Node <T> * pos);
	void push_back(const T & n);
	void pop_back();
	void push_front(const T & n);
	void pop_front();
	void print(); //print list , support built-in type only
	void print_inverse(); //print list inversely , for test
	T & retrieve(_Node<T> * pos); //return the reference of the element data at pos
	T & top(); //return the reference of the element data at top
	T & back(); //return the reference of the element data at bottom
private:

	_Node<T> * first;
	_Node<T> * last;

};



/******************************************************************************************
constructor
******************************************************************************************/
template<typename T>
List<T>::List()
{
	first = new _Node<T>;
	last = first;
}

/******************************************************************************************
destructor
******************************************************************************************/
template<typename T>
List<T>::~List()
{
	_Node<T> * temp = first;
	while (temp->next != NULL)
	{
		first = temp->next;
		delete temp;
		temp = first;
	}
}

/******************************************************************************************
find the first node that equals n
******************************************************************************************/
template<typename T>
_Node<T> * List<T>::find(const T & n)
{
	_Node<T> * temp = first;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->Data == n)
			return temp;
	}
	cout << "failed find element in list " << endl;
	return NULL;
}

/******************************************************************************************
insert n in front of pos
******************************************************************************************/
template<typename T>
void List<T>::insert(const T & n,_Node <T> * pos) //pos前一个位置
{
	_Node<T> * temp = first;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp == pos)
		{
			_Node<T> * p = new _Node<T>;
			p->Data = n;
			p->pref = temp->pref;
			p->next = pos;

			p->pref->next = p;
			pos->pref = p;

			//break;   //别犯傻 (╯°Д°)╯︵┻━┻
			return;
		}
	}

	if (pos != last)
	{
		cout << "failed in insert, can not find  pos." << endl;
		exit(0);
	}
}

/******************************************************************************************
add node n back
******************************************************************************************/
template<typename T>
void List<T>::push_back(const T & n)
{
	_Node<T> * p = new _Node<T>;

	p->Data = n;
	p->pref = last;
	last->next = p;

	last = p;
}

/******************************************************************************************
delete the last node
******************************************************************************************/
template<typename T>
void List<T>::pop_back()
{
	_Node<T> * temp = last;
	last = last->pref;
	last->next = NULL;

	delete temp;
}

/******************************************************************************************
print the whole list
******************************************************************************************/
template <typename T>
void List<T>::print()
{
	_Node<T> * temp = first;
	cout << "{ ";
	while (temp->next != NULL)
	{
		temp = temp->next;
		cout<< temp->Data<<",";
	}
	cout << "}" << endl;
}

/******************************************************************************************
print the whole list inversely , for test 
******************************************************************************************/
template <typename T>
void List<T>::print_inverse()
{
	_Node<T> * temp = last;
	cout << "{ ";
	cout << temp->Data << ",";
	while (temp->pref != first)
	{
		temp = temp->pref;
		cout << temp->Data << ",";
	}
	cout << "}" << endl;
}

/******************************************************************************************
add node n at head
******************************************************************************************/
template <typename T>
void List<T>::push_front(const T & n)
{
	_Node<T> * p = new _Node<T>;

	p->Data = n;
	p->next = first->next;
	p->pref = first;

	first->next->pref = p;
	first->next = p;
}

/******************************************************************************************
delete the first node
******************************************************************************************/
template <typename T>
void List<T>::pop_front()
{
	_Node<T> * p = first->next;

	first->next = p->next;
	p->next->pref = first;
	
	delete p;
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
T & List<T>::retrieve(_Node<T> * pos)
{
	_Node<T> * temp = first;

	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp == pos)
		{
			return pos->Data;
		}
	}

	if (pos != last)
	{
		cout << "failed in retrieve, can not find  pos." << endl;
		exit(0);
		return last->Data;
	}
	else
		return last->Data;
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
T & List<T>::top()
{
	return retrieve(first->next);
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
T & List<T>::back()
{
	return retrieve(last);
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
bool List<T>::isEmpty()
{
	if (first == last)
		return true;
	else
		return false;
}

#endif