#include "Stack.h"

Stack::Node::Node(const Node &sec)
{
	value = sec.value;
}


Stack::Stack(const Stack &sec)
{
	Node *temp, *temp1;
	size = sec.size;
	top = new Node(sec.top->value);

	temp = top;
	temp1 = sec.top->next;

	while (temp1!=nullptr)
	{
		temp->next = new Node(temp1->value);
		temp = temp->next;
		temp1 = temp1->next;
	}
	

}

Stack::~Stack()
{
	Node *temp;
	temp = top;
	while (top!=nullptr)
	{
		temp = top;
		top = temp->next;
		delete temp;
	}
}

Stack &Stack::operator=(const Stack &sec)
{
	Node *temp, *temp1;
	if (top != sec.top)
	{
		size = sec.size;
		
		top = new Node(sec.top->value);

		temp = top;
		temp1 = sec.top->next;

		while (temp1 != nullptr)
		{
			temp->next = new Node(temp1->value);
			temp = temp->next;
			temp1 = temp1->next;
		}

	}
	return *this;
}

Stack & Stack::operator+=(int sec)
{
	if (top==nullptr) 
	{
		top = new Node(sec);
		size++;
	}
	else
	{
		Stack::Node*temp = new Node(sec);
		temp->next = top;
		top = temp;
		size++;

	}
	
	return *this;
}

Stack & Stack::operator-=(int count)
{
	int i;
	if (count > size)
	{
		cout << "Error " << endl;
		return *this;
	}
	Node *temp;
	for (i = 0; i < count; i++)
	{
		temp = top;
		top = temp->next;

		delete temp;


	}
	return *this;
}

bool Stack::operator==(const Stack &sec) const
{
	Node *temp, *tempsec;
	temp = top;
	tempsec = sec.top;
	if(size!=sec.size)
	return false;
	while (temp != nullptr || tempsec != nullptr)
	{
		if (temp->value != tempsec->value)
			return false;
		temp = temp->next;
		tempsec = tempsec->next;
    }

	return true;

}

bool Stack::operator!=(const Stack &sec) const
{
	if(sec==*this)
	return false;

	return true;
}

Stack & Stack::operator!()
{
	Stack newstack;
	Node *temp = top;
	while (temp != nullptr)
	{
		newstack += temp->value;
		temp = temp->next;
	}
	(*this) = newstack;

	return *this;
}

ostream & operator<<(ostream &out, const Stack &sec)
{
	
	for (Stack::Node *temp = sec.top; temp != nullptr; temp = temp->next)
		out << temp->value << endl;
	return out;
}
