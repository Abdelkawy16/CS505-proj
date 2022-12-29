#pragma once
#include <string>
#include "Meal.cpp"
#include "../Data.Structures/List.h"
#include "../Data.Structures/List.cpp"
using namespace std;
class Customer
{
private:
	string name;
	int id;
	List* orders;
	static int current_id;

public:
	Customer(string);
	~Customer();
	void getOrders();
	void addOrder(Meal);
	string getName();
};

