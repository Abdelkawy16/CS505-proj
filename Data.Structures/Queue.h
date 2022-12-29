#pragma once
#include "../Models/Customer.h"
#include "../Models/Customer.cpp"

class Queue
{
private:
	class node
	{
	public:
		Customer* e;
		node* next;
	};


	node* front, * rear;
	int count;


public:
	Queue();
	~Queue();
	void enqueue(Customer*);
	Customer* dequeue();
	void queueFront(Customer*) const;
	bool queueIsEmpty() const;
	int  queueLength() const;
};
