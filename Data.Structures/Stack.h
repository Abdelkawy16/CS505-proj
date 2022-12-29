#pragma once
class Stack
{

private:

	class node
	{
	public:
		string e;
		node* next;
	};
	node* top;

public:

	Stack();
	~Stack();
	void push(string);
	string pop();
	string stackTop() const;
	bool stackIsEmpty() const;


};