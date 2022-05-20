#include<typeinfo>
#include <iostream>
using namespace std;
template<class T>
//class template
class MyArr 
{
	T *Arr;
	int size;

public:
	//ctor
	MyArr(T*arr,int size_):size(size_) {
		Arr = new T[size];
			for (int i = 0; i < size; i++) {
				Arr[i] = arr[i];
			}
	}
	//print
	friend ostream& operator <<(ostream& cout, const MyArr& sec)
	{
		for (int i = 0; i < sec.size; i++)
			cout << sec.Arr[i] << endl;

		return cout;
	}
	//print name type template
	void isType();
	//return T by index
	T &operator [](int);
	MyArr &operator +=(T);//add T to arr 


};

template<class T>
inline void MyArr<T>::isType()
{
	cout << typeid(T).name()<<endl;//print type name
}

template<class T>
inline T & MyArr<T>::operator[](int index)
{
	if (index < 0)//check index taken or throw msg
		throw string("Invalid index!!");
	else
		return Arr[index];
}

template<class T>
inline MyArr<T> & MyArr<T>::operator+=(T sec)
{
	T *temp;
	temp = new T[size];
	for (int i = 0; i < size; i++)
		temp[i] = Arr[i];

	delete[]Arr;
	size++;
	Arr = new T[size];
	for (int i = 0; i < size; i++)
		Arr[i] = temp[i];
	Arr[size - 1] = sec;
	return *this;

}
