#include <iostream>
#include "mylist.h"
#include "mystack.h"
using namespace std;

struct Node
{
	int a = 6;
	double b = 9.9;

	Node(int intin, double doublein){ a = intin; b = doublein; };
	Node(){};

	bool operator == (const Node & n)   //overload operator == 
	{
		return (this->a == n.a && this->b == n.b) ? true : false;
	}
};
ostream & operator << (ostream & o, const Node & n)   //overload operator << to print struct Node
{
	return o << "(" << n.a << "," << n.b <<")";
}


/***********************************************************************************/

void testList()
{
	List<int> intlist;
	List<double> doublelist;

	for (int i = 0; i < 10; i++)
	{
		double dab = 0.3*i;
		intlist.push_back(i);
		doublelist.push_back(dab);
	}


	intlist.insert(100, intlist.find(9));
	intlist.push_back(50);
	intlist.pop_front();
	intlist.push_front(77);
	intlist.print();
	intlist.pop_front();
	intlist.pop_back();
	intlist.print();
	intlist.print_inverse();
	intlist.insert(499, intlist.find(5));
	intlist.print_inverse();
	doublelist.print();


	List<Node> nodelist;

	for (int i = 0; i < 10; i++)
	{
		int a = i;
		double b = 0.3*i;
		Node n(a, b);
		nodelist.push_back(n);
	}

	int i = 3;
	int a = i;
	double b = 0.3*i;
	Node n(a, b);
	nodelist.insert(n, nodelist.find(n));
	nodelist.print();
}

void testStack()
{
	Stack<int> intstack;
	Stack<double> doublestack;

	for (int i = 0; i <= 9; i++)
	{
		intstack.push(i);
		cout << intstack.top() << " ";
	}
	cout << endl;

	for (int i = 0; i <= 9; i++)
	{
		double dab = 0.3*i;
		doublestack.push(dab);
		cout << doublestack.top() << " ";
	}

	cout << endl;
	for (int i = 0; i <= 9; i++)
	{
		cout << intstack.top() << " ";
		intstack.pop();
		
	}
	cout << endl;

	for (int i = 0; i <= 9; i++)
	{
		cout << doublestack.top() << " ";
		doublestack.pop();
	}
	cout << endl;



	Stack<Node> nodestack;
	
	for (int i = 0; i < 10; i++)
	{
		int a = i;
		double b = 0.3*i;
		Node n(a, b);
		nodestack.push(n);
		cout << nodestack.top() << endl;
	}

	for (int i = 0; i < 10;i++)
	{
		cout << nodestack.top() << endl;
		nodestack.pop();
		
	}

	if (nodestack.isEmpty())
		cout << "nodestack is empty " << endl;
}


void main()
{
	//testList();
	testStack();
	cout << "program still running" << endl;
}