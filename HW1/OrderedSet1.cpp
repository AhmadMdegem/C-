#include "OrderedSet.h"

int main()
{
	int *group, *group1, size, size1, i;

	cout << "Enter size of the group" << endl;
	cin >> size;
	group = new int[size];
	cout << "enter the element: " << endl;
	for (i = 0; i < size; i++)
		cin >> group[i];

	cout << "Enter size of the group1" << endl;
	cin >> size1;
	group1 = new int[size1];
	cout << "enter the element: " << endl;
	for (i = 0; i < size1; i++)
		cin >> group1[i];

	OrderedSet OrderedSet1(group, size), OrderedSet2(group1, size1), empty;
	cout << "the first group is:";
	OrderedSet1.print();
	cout << "the secend group is:";
	OrderedSet2.print();
	cout << "the intersection between the group1 & group2 is: ";
	OrderedSet OrderedSet3 = OrderedSet1.intersection(OrderedSet2);
	OrderedSet3.print();
	cout << "the Consolidation between the group1 & group2 is: ";
	OrderedSet OrderedSet5 = OrderedSet1.Consolidation(OrderedSet2);
	OrderedSet5.print();
	cout << "the intersection between the group1 & group3 is: ";
	OrderedSet empty1 = OrderedSet1.intersection(empty);
	empty1.print();
	cout << "the difference between the group1 & group2 is: ";
	OrderedSet OrderedSet4 = OrderedSet1.difference(OrderedSet2);
	OrderedSet4.print();

	if (OrderedSet1.contains(empty))
	{
		cout << "the OrderedSet1 contains empty orederedSet!!" << endl;
	}
	else
	{
		cout << "the OrderedSet1  doesn't contain it!!" << endl;
	}
	if (OrderedSet2.contains(OrderedSet1))
	{
		cout << "the OrderedSet2 contain it!!" << endl;
	}
	else
	{
		cout << "orderedSet2 doesn't contain orderedSet1 " << endl;
	}
	return 0;
}