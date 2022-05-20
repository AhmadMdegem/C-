#include "OrderedSet.h"

bool OrderedSet::check(int *group, int siz, int a)
{
	int i;
	for (i = 0; i < siz; i++)
		if (group[i] == a)
			return false;

	return true;
}



OrderedSet::OrderedSet(int * arr, int siz)
{
	int i, c = 0, k = 0;



	for (i = 0; i < siz; i++)
	{
		if (check(arr, i, arr[i]))
			c++;
	}

	size = c;
	group = new int[size];
	if (group == NULL)
	{
		cout << "Error!!" << endl;
		exit(1);
	}

	for (i = 0; i < siz; i++)
	{
		if (check(arr, i, arr[i]))
		{
			group[k] = arr[i];
			k++;
		}
	}

	sort(group, size);
}

OrderedSet::OrderedSet(const OrderedSet & groupi)
{
	int i;
	group = new int[groupi.size];
	if (group == NULL)
	{
		cout << "Error!!" << endl;
		exit(1);
	}

	for (i = 0; i < groupi.size; i++)
		group[i] = groupi.group[i];

	size = groupi.size;


}

OrderedSet OrderedSet::intersection(const OrderedSet & group3)
{
	int i, j, c = 0, k = 0;
	OrderedSet help;
	for (i = 0; i < size; i++)
		for (j = 0; j < group3.size; j++)
			if (group[i] == group3.group[j])
				c++;

	help.group = new int[c];
	if (help.group == NULL) {
		cout << "Error!!";
		exit(1);
	}
	help.size = c;
	for (i = 0; i < size; i++)
		for (j = 0; j < group3.size; j++)
			if (group[i] == group3.group[j])
			{
				help.group[k++] = group[i];
			}



	return help;
}

OrderedSet OrderedSet::difference(const OrderedSet & groubh)
{
	int c = 0, i, flag = 0, j, k = 0;
	OrderedSet help;
	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < groubh.size&&flag == 0; j++)
		{
			if (group[i] != groubh.group[j])
				flag = 0;
			else
			{
				flag = 1;
			}
		}
		if (flag == 0)
			c++;
	}
	help.size = c;
	help.group = new int[help.size];
	if (help.group == NULL)
	{
		cout << "Error!!" << endl;
		exit(1);
	}

	for (i = 0; i < size; i++)
	{
		flag = 0;
		for (j = 0; j < groubh.size&&flag == 0; j++)
		{
			if (group[i] != groubh.group[j])
				flag = 0;
			else
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			help.group[k] = group[i];
			k++;
		}
	}

	return help;
}

bool OrderedSet::contains(const OrderedSet &grouph)
{
	int flag = 0, i, j;
	if (grouph.size <= size)
	{
		for (i = 0; i < grouph.size; i++)
		{
			flag = 0;
			for (j = 0; j < size&&flag == 0; j++)
			{
				if (grouph.group[i] != group[j])
					flag = 0;
				else
				{
					flag = 1;
				}
			}
			if (flag == 0)
				return false;
		}
		return true;
	}
	else
		return false;
}


int * OrderedSet::getgroup()
{
	return group;
}

int OrderedSet::getsize()
{
	return size;
}

void OrderedSet::print()
{
	if (size == 0)
		cout << "{ }" << endl;
	else {
		cout << "{";
		for (int i = 0; i < size - 1; i++)
		{
			cout << group[i] << ",";
		}
		cout << group[size - 1] << "}" << endl;
	}



}
bool OrderedSet::emptycheke()
{
	return size==0;
}
void OrderedSet::sort(int *group1, int sizee)
{
	int i, j, temp = 0;
	for (i = 0; i < sizee; i++)
		for (j = i; j < sizee; j++)
		{
			if (group1[i] > group1[j])
			{
				temp = group1[j];
				group1[j] = group1[i];
				group1[i] = temp;
			}
		}
}
OrderedSet OrderedSet::Consolidation(const OrderedSet &groubh)
{
	int i, k, j, flag = 0, c = 0;
	OrderedSet newgroubh;


	for (i = 0; i < groubh.size; i++)
	{
		flag = 0;
		for (j = 0; j < size&&flag == 0; j++)
		{
			if (groubh.group[i] != group[j])
				flag = 0;
			else
			{
				flag = 1;
			}
		}
		if (flag == 0)
			c++;

	}
	newgroubh.size = size + c;
	newgroubh.group = new int[newgroubh.size];
	if (newgroubh.group == NULL)
	{
		cout << "Error!!" << endl;
		exit(1);
	}
	for (k = 0; k < size; k++)
		newgroubh.group[k] = group[k];

	for (i = 0; i < groubh.size; i++)
	{
		flag = 0;
		for (j = 0; j < size&&flag == 0; j++)
		{
			if (groubh.group[i] != group[j])
				flag = 0;
			else
			{
				flag = 1;
			}
		}
		if (flag == 0)
			newgroubh.group[k++] = groubh.group[i];

	}


	return newgroubh;
}
