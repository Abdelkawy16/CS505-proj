#include "Queue.h"
#include <iostream>
using namespace std;



Queue::Queue()
{
	front = NULL; rear = NULL; count = 0;
}



Queue::~Queue()
{
	node* cursor;
	while (front != NULL)
	{
		cursor = front;
		front = front->next;
		delete cursor;
	}
}


void Queue::enqueue(Customer* v)
{
	node* pnew = new node;
	pnew->e = v;  pnew->next = NULL;
	if (queueIsEmpty())
	{
		front = pnew; rear = pnew;
	}
	else
	{
		rear->next = pnew; rear = pnew;
	}
	count++;
}


Customer* Queue::dequeue()
{
	node* cursor;
	Customer* _customer = new Customer("Not Found");
	if (queueIsEmpty()) cout << "Queue is Empty" << endl;
	else
	{
		_customer = front->e;
		cursor = front;
		front = front->next;
		delete cursor;  count--;
	}
	return _customer;
}


void Queue::queueFront(Customer* v) const
{
	node cursor;
	if (queueIsEmpty()) cout << "Queue is Empty" << endl;
	else { v = front->e; }
}



bool Queue::queueIsEmpty() const
{
	return (count == 0);
}



int Queue::queueLength() const
{
	return count;
}