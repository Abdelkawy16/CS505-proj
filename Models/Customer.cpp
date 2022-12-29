#include "Customer.h"
#include <iostream>
using namespace std;

int Customer::current_id = 0;

Customer::Customer(string _name) :id(current_id++)
{
	name = _name;
	orders = new List;
}

Customer::~Customer()
{
	cout << "finished";
}

void Customer::getOrders()
{
	orders->display();
}

void Customer::addOrder(Meal _meal)
{
	orders->insertEnd(orders->listSize() + 1, _meal);
}

string Customer::getName() {
	return name;
}