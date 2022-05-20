#include"Sort.h"
#include"template1.h"
#include"Date.h"
int main()
{
	int arr[] = { 12,11,9,8,1,14,10,20,3,16 };
	Date datetest[] = { {1,2,1998},{16,10,1998} };
	//arr int
	SelectionSort(arr, 10);
	PrintArray(arr, 10);
	MyArr<int> arr1(arr,10);
	cout << arr1;
	arr1 += 5;
	cout << arr1;

	//arr Date
	MyArr<Date> date1(datetest, 2);
	Date date2(1, 16, 1998);
	cout << date1;
	date1 += date2;
	cout << date1;

	return 0;
}