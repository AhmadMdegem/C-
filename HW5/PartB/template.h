#include<typeinfo>
#include<string>
using namespace std;
template<class T>
//class template
class MyArr
{
	T* Arr;
	int size;

public:
	
	MyArr() { size = 0; Arr = new T; }//defualt ctor
	MyArr(T* arr, int size_) :size(size_)//ctor
	{
		Arr = new T[size];
		for (int i = 0; i < size; i++) {
			Arr[i] = arr[i];
		}
	}
	void isType();//print the type of the template
	T& operator [](int);//operator check index if is good return the value else print msg
	MyArr& operator +=(const T&);//operator += to add elemnt to arr 
	MyArr& operator -=(const T&);//operator -= to delete elemnt from arr
	

	friend ostream& operator <<(ostream& cout, const MyArr& sec)//output function
	{
		cout << typeid(sec).name() << std::endl;
		for (int i = 0; i < sec.size; i++)
			cout << sec.Arr[i] << std::endl;
		return cout;
	}
	bool is_sort();//check if the arr is sort or no
	T* findmax();//find the max in the arr and return it
	T* finmin();//find the min in the arr and return it

};
template<class T>

inline void MyArr<T>::isType()
{
	std::cout << tybeid(*this).name() << std::endl;//print type of the template
}

template<class T>
inline T& MyArr<T>::operator[](int index)
{
	if (index < 0)//check the index if it taken else throw msg
		throw string("Invalid index!!");
	else
		return Arr[index];//return the value 
}

template<class T>
inline MyArr<T>& MyArr<T>::operator+=(const T& sec)
{
	T* temp;
	if (size == 0)//if the arr are null 
	{
		size++;
		Arr = new T[size];
		Arr[0] = sec;
	}
	else {
		size++;
		temp = new T[size];
		for (int i = 0; i < size-1; i++)
			temp[i] = Arr[i];
		temp[size - 1] = sec;

		delete[]Arr;
		Arr = new T[size];
		for (int i = 0; i < size; i++)
			Arr[i] = temp[i];

	}
	return *this;
}

template<class T>
inline MyArr<T> & MyArr<T>::operator-=(const T& sec)
{
	T* temp;
	temp = new T[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (Arr[i] != sec)
			temp[i] = Arr[i];
	}
	delete[]Arr;
	size--;
	Arr = new T[size];
	for (int i = 0; i < size; i++)
		Arr[i] = temp[i];

	return *this;
}



template<class T>
inline bool MyArr<T>::is_sort()
{
	for (int i = 1; i < size; i++)
		if (Arr[i] < Arr[i - 1])
			return false;

	return true;
}

template<class T>
inline T* MyArr<T>::findmax()
{
	T* max = &Arr[0];
	for (int i = 0; i < size; i++)
	{
		if (*max < Arr[i])
			max = &Arr[i];
	}
	return max;
}

template<class T>
inline T* MyArr<T>::finmin()
{
	if (Arr == NULL)
		return NULL;

	T* min = &Arr[0];
	for (int i = 0; i < size; i++)
	{
		if (  Arr[i]< *min)
			min = &Arr[i];
	}
	return min;
}
