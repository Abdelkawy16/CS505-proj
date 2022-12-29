#pragma once
#include "../Models/Meal.cpp"
class List
{
	class node
	{
	public:
		int key;
		Meal data;
		node* next;
	};

	node* head, * cursor, * prev;

public:

	List();
	~List();
	bool listIsEmpty() const;
	bool curIsEmpty() const;
	void toFirst();
	bool atFirst() const;
	void advance();
	void toEnd();
	bool atEnd() const;
	int  listSize() const;
	void updateData(const Meal&);
	void retrieveData(Meal&, int&) const;
	void insertFirst(const int&, const Meal&);
	void insertAfter(const int&, const Meal&);
	void insertBefore(const int&, const Meal&);
	void insertEnd(const int&, const Meal&);
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void makeListEmpty();
	bool search(const int&);
	void orderInsert(const Meal&, const int&);
	void traverse();
	void ReverceList(node* h);
	void display();

};
