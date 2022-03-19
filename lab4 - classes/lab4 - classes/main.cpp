#include "sort.h"
#include <cstdio>

int main() {

	Sort arr0;
	printf("%s", "Default array is: ");
	arr0.Print();

	Sort arr1 = { "10,40,100,5,70" };
	printf("%s", "Array 1 is: ");
	arr1.Print();

	printf("%s", "Element from index 3 is: ");
	printf("%i\n", arr1.GetElementFromIndex(3));

	Sort arr2 = {10,30,6};
	printf("%s", "Array 2 is: ");
	arr2.Print();

	arr2.QuickSort(false);
	printf("%s", "Array 2 in sorted order is: ");
	arr2.Print();

	Sort arr3 = { 7, 1, 9, 5,1,90,32,15 };
	printf("%s", "Array 3 is: ");
	arr3.Print();

	arr3.InsertSort(false);
	printf("%s", "Sorted array 3 is: ");
	arr3.Print();

	int arr[] = { 1,52,36,12,86,4 };
	Sort arr4 = { arr, 6 };
	printf("%s", "Array 4 is: ");
	arr4.Print();

	arr4.BubbleSort(true);
	printf("%s", "Sorted array 4 is: ");
	arr4.Print();

	printf("%s", "Element count for array 4 is: ");
	printf("%i", arr4.GetElementsCount());

	return 0;
}

///nu stiu de ce uneori crapa programul la final (returneaza un cod de eroare si pe debug ma duce pe instructiunea:
//	if ( has_cctor) _cexit()
//			:-??
//statistic, ruleaza bine in 70% din cazuri xD