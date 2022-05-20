#include<iostream>
using namespace std;
class OrderedSet {
	int *group;
	int size;
	bool check(int *, int, int);
	void sort(int *, int size);

public:
	OrderedSet() :group(NULL), size(0) {}
	OrderedSet(int *arr, int siz);
	OrderedSet(const OrderedSet &);
	~OrderedSet() {
		delete[]group;
	}
	OrderedSet intersection(const OrderedSet &);
	OrderedSet difference(const OrderedSet&);
	bool contains(const OrderedSet &);
	int *getgroup();
	int getsize();
	void print();
	bool emptycheke();
	OrderedSet Consolidation(const OrderedSet&);
};
