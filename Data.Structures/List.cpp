#include <iostream>
#include"List.h"
using namespace std;
using std::string;



List::List()
{
	head = NULL; cursor = NULL;  prev = NULL;
}

List::~List()
{
	makeListEmpty();
}


bool List::listIsEmpty() const
{
	return (head == NULL);
}

bool List::curIsEmpty() const
{
	return (cursor == NULL);
}


void List::toFirst()
{
	cursor = head;  prev = NULL;
}

bool List::atFirst() const
{
	return (cursor == head);
}

void List::advance()
{
	prev = cursor;
	cursor = cursor->next;
}

void List::toEnd()
{
	toFirst();
	if (!listIsEmpty())
		while (cursor->next != NULL) advance();
}

bool List::atEnd() const
{
	if (listIsEmpty()) return true;
	else if (curIsEmpty()) return false;
	else return (cursor->next == NULL);
}

int List::listSize() const
{
	node* q; 	int count;
	q = head;	count = 0;
	while (q != NULL)
	{
		count++; 	q = q->next;
	}
	return count;
}

void List::updateData(const Meal& d)
{
	cursor->data = d;
}

void List::retrieveData(Meal& d, int& k) const
{
	k = cursor->key;
	d = cursor->data;
}

void List::insertFirst(const int& k, const Meal& d)
{
	node* pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = head;
	head = pnew;
	cursor = head;
	prev = NULL;
}

void List::insertAfter(const int& k, const Meal& d)
{
	node* pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor->next;
	cursor->next = pnew;
}

void List::insertBefore(const int& k, const Meal& d)
{
	node* pnew;
	pnew = new node;
	pnew->key = k; pnew->data = d;
	pnew->next = cursor;
	prev->next = pnew;
	cursor = pnew;
}

void List::insertEnd(const int& k, const Meal& d)
{
	if (listIsEmpty()) insertFirst(k, d);
	else { toEnd(); insertAfter(k, d); }
}

void List::deleteNode()
{
	node* q;
	if (!curIsEmpty())
	{
		if (atFirst())
		{
			q = cursor;
			cursor = cursor->next;
			head = cursor;
			delete q;
		}

		else
		{
			q = cursor;
			cursor = cursor->next;
			prev->next = cursor;
			delete q;
		}
	}
}


void List::deleteFirst()
{
	if (!listIsEmpty()) { toFirst(); deleteNode(); }
}


void List::deleteEnd()
{
	if (!listIsEmpty()) { toEnd(); deleteNode(); }
}


void List::makeListEmpty()
{
	toFirst();
	while (!listIsEmpty())
		deleteNode();
}


bool List::search(const int& k)
{
	bool found = false;
	toFirst();
	while ((!found) && (cursor != NULL))
		if (k == cursor->key)  found = true;
		else advance();
	return found;
}


void List::orderInsert(const Meal& d, const int& k)
{
	toFirst();
	while ((cursor != NULL) && (k > cursor->key))
		advance();
	if (prev == NULL)  insertFirst(k, d);
	else insertBefore(k, d);
}


void List::traverse()
{


	toFirst();
	while (!curIsEmpty())
	{
		cout << cursor->data << endl;
		advance();
	}
}

void List::ReverceList(node* h)
{

	while (!curIsEmpty())
	{
		if (h == NULL)
			return;
		else
		{
			ReverceList(h->next);

			cout << h->data;
		}
	}

}

void List::display()
{
	node* q;
	q = head;
	while (q != NULL)
	{
		cout << MealString[q->data];
		if (q->next != NULL)
			cout << " - ";
		q = q->next;
	}
	cout << endl;
}

