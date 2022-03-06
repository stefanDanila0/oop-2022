#include "NumberList.h"

int main() {
	NumberList numbers{};

	numbers.Init();
	numbers.Add(12);
	numbers.Add(1);
	numbers.Add(5);
	numbers.Add(6);
	numbers.Add(4);
	numbers.Add(9);
	numbers.Add(13);

	numbers.Print();
	numbers.Sort();
	numbers.Print();

}