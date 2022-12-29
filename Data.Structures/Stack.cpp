#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
	top = NULL;
}


Stack::~Stack()
{
	node* cursor;
	while (top != NULL)
	{
		cursor = top;	top = top->next;
		delete cursor;
	}
}

bool Stack::stackIsEmpty() const
{
	return (top == NULL);
}

void Stack::push(string v)
{
	node* pnew = new node;
	pnew->e = v; pnew->next = top; top = pnew;
}

string Stack::pop()
{
	string s = "";
	node* cursor;
	if (stackIsEmpty()) cout << "Stack Underflow" << endl;
	else
	{
		s = top->e; cursor = top;
		top = top->next; delete cursor;
	}
	return s;
}

string Stack::stackTop() const
{
	string s = "";
	node* cursor;
	if (stackIsEmpty()) cout << "Stack Underflow" << endl;
	else
	{
		s = top->e;
	}
	return s;
}
