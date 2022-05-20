#include<iostream>

using namespace std;

template<class G>
//function swap value between two variables
void Swap(G &a, G &b)
{
	G temp;
	temp = a;
	a = b;
	b = temp;

}

template<class T>
//template to sort arr small to bigger
void SelectionSort(T *arr, int size)
{
	int min = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			if (arr[i] <arr[j])
			{
				Swap(arr[j], arr[i]);
			}
}
 
//template to print
template<class T>
void PrintArray(T *arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
}
