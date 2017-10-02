#ifndef _MYSTACK_H_
#define _MYSTACK_H_

#include <iostream>
#include "mylist.h"

using namespace std;

template <typename T>
class Stack
{
public:
	bool isEmpty();
	void push(const T & elem);
	void pop();
	T & top();

	/*Stack();
	~Stack();*/
private:
	List<T> s;
};

/******************************************************************************************
test stack is empty or not
******************************************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
	return s.isEmpty();
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
void Stack<T>::push(const T & elem)
{
	s.push_back(elem);
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		cout << "failed to pop in Stack<T>::pop(),empty stack" << endl;
		exit(0);
	}
	else
		s.pop_back();
}

/******************************************************************************************

******************************************************************************************/
template <typename T>
T & Stack<T>::top()
{
	return s.back();
}

#endif