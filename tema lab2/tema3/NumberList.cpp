#include "NumberList.h"
#include <iostream>

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	if (x < 10) {
		numbers[count++] = x;
		return true;
	}
	else return false;
}

void NumberList::Sort() {
	for (int i = 0; i < count; i++)
		for (int j = 0; j< count - i - 1; j++)
			if (numbers[j] > numbers[j+1]) {
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
}

void NumberList::Print() const {
	for (int i = 0; i < count; i++) {
		printf("%d", numbers[i]);
		printf(" ");
	}
	printf("\n");
}
