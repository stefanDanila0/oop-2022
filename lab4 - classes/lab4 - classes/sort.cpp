#define _CRT_SECURE_NO_WARNINGS

#include "sort.h"
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <cstdio>



Sort::Sort(): arr(new int[5]{1,5,2,4,3}) {
	arr_no = 5;
}

Sort::Sort(int min, int max, unsigned arr_no) {
	this->arr_no = arr_no;
	arr = new int[arr_no];
	for (unsigned i = 0; i < arr_no; i++) {
		arr[i] = min + (rand() % (max - min + 1));
	}
}

Sort::Sort(int* arr, unsigned arr_no) {
	this->arr = new int[arr_no];
	this->arr_no = arr_no;
	for (unsigned i = 0; i < arr_no; i++) {
		this->arr[i] = arr[i];
	}
}

Sort::Sort(unsigned arr_no, ...) {
	va_list args;
	va_start(args,arr_no);
	this->arr_no = arr_no;
	arr = new int[arr_no];
	for (unsigned i = 0; i < arr_no; i++) {
		arr[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* array) {
	arr_no = 0;
	unsigned size = strlen(array);
	unsigned commas = 1;
	for (unsigned i = 0; i < size; i++) {
		if (array[i] == ',')
			commas++;
	}
	arr = new int[commas];
	char* temp = new char((size + 1) * sizeof(char));
	strcpy(temp, array);
	char* str = strtok(temp, ",");
	unsigned idx = 0;
	while (str != nullptr) {
		int var = atoi(str);
		arr[idx] = var;
		idx++;
		arr_no++;
		str = strtok(nullptr, ",");
	}
}


void Sort::InsertSort(bool ascendent) {
	if (ascendent == false) {
		for (unsigned idx = 1; idx < arr_no; idx++) {
			int key = arr[idx];
			int j = idx - 1;
			while (key > arr[j] && j >= 0) {
				arr[j + 1] = arr[j];
				--j;
			}
			arr[j + 1] = key;
		}
	}
	if (ascendent == true) {
		for (unsigned idx = 1; idx < arr_no; idx++) {
			int key = arr[idx];
			unsigned j = idx - 1;
			while (key < arr[j] && j >= 0) {
				arr[j+1] = arr[j];
				--j;	
			}
			arr[j + 1] = key;
		}
	}
}

int Sort::partition(int arr[], int low, int high, bool ascendent) {
	int pivot = arr[high];
	int temp;
	int i = (low - 1);
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;

	return (i + 1);
}

void Sort::quick(int arr[], int low, int high, bool ascendent) {
	if (low < high) {
		int piv = partition(arr, low, high, ascendent);
		quick(arr, low, piv - 1,ascendent);
		quick(arr, piv + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent) {
	quick(arr, 0, arr_no-1, ascendent);
	if (ascendent == false) {
		int i = 0;
		int j = arr_no - 1;
		while (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
}

void Sort::BubbleSort(bool ascendent) {
		unsigned i, j, temp = 0;
		if (ascendent == true) {
			for (i = 0; i < arr_no; i++)
				for (j = 0; j < arr_no - i - 1; j++)
					if (arr[j] > arr[j + 1]) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
		}
		if (ascendent == false) {
			for (i = 0; i < arr_no; i++)
				for (j = 0; j < arr_no - i - 1; j++)
					if (arr[j] < arr[j + 1]) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
		}
}

void Sort::Print() const {
	if (arr_no > 0) {
		for (unsigned i = 0; i < arr_no; i++) {
			printf("%i", arr[i]);
			printf(" ");
		}
	}
	else printf("-1");
	printf("\n\n");
}

unsigned int Sort::GetElementsCount() const {
	if (arr_no > 0)
		return arr_no;
	return -1;
}

int Sort::GetElementFromIndex(unsigned index) const {
	if (index < arr_no)
		return arr[index];
	else return -1;
}

Sort::~Sort() {
	delete[] arr;
}