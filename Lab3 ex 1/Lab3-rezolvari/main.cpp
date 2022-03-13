#include "Math.h"
#include <cstdio>

int main() {
	Math M;

	printf("%i\n", M.Add(2, 3));
	printf("%i\n", M.Add(2, 3, 8));
	printf("%f\n", (double)M.Add(2.7, 3.3));
	printf("%f\n", (double)M.Add(2.7, 3.3, 4.3));//loss of precision :-??
	printf("%i\n", M.Add(5, 3, 7, 8, 9, 10));

	printf("%i\n", M.Mul(2, 6));
	printf("%i\n", M.Mul(2, 6, 3));
	printf("%f\n", (double)M.Mul(2.2, 6.5));//loss of precision :-??
	printf("%f\n", (double)M.Mul(2.2, 6.5, 0.5));//loss of precision :-??

	const char* sir1 = "Sanatate..!";
	const char* sir2 = "Multumesc..";

	puts(M.Add(sir1, sir2));

	return 0;
}