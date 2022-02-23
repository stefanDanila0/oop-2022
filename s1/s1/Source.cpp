
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int convert(const char* s) {
	int numar = 0;
	int i;
	for (i = 0; s[i] && s[i] != '\n'; i++)
		numar = numar * 10 + s[i] - 48;
	return numar;
}





int solve() {
	FILE* fisier = fopen("Text.txt", "r");
	if (fisier == NULL) {
		printf("Eroare");
		return 0;
	}
	char sir[100];
	int suma = 0;
	while (fgets(sir, sizeof(sir), fisier) != NULL) {
		suma += convert(sir);
	}
	return suma;
}

int main() {
	int rezultat = solve();
	printf("%d", rezultat);
	return 0;
}