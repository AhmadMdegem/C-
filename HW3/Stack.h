#include<iostream>
using namespace std;

class Stack
{
	class Node 
{
		int value;
		Node *next;
public:
	Node(int a) :value(a), next(NULL) {}
	Node(const Node &);
	friend Stack;
	friend ostream & operator << (ostream &, const Stack &);


};
	Node *top;
	int size;

public:
	Stack() :top(nullptr), size(0){}
	Stack(const Stack&);
	~Stack();
	Stack & operator =(const Stack&);
	Stack & operator +=(int);
	Stack & operator -=(int);
	bool  operator ==(const Stack&)const;
	bool  operator !=(const Stack&)const;
	Stack & operator !();
	friend ostream & operator << (ostream &,const Stack &);






};