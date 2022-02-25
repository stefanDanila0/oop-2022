#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <string>

// A function to implement bubble sort

void swap(char*& arr1, char*& arr2) {
	char* aux;
	aux = arr1;
	arr1 = arr2;
	arr2 = aux;
}

void sort(char* arr[], int tokens_count) {
	int i, j;

	for (i = 0; i < tokens_count - 1; i++)
		for (j = 0; j < tokens_count - 1; j++) {
			if (strlen(arr[j]) < strlen(arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
			if (strlen(arr[j]) == strlen(arr[j + 1])) {
				if (strncmp(arr[j], arr[j + 1], 1) > 0)
					swap(arr[j], arr[j + 1]);
			}

		}
}
//ex3
int main() {
	char str[256];
	char* token;
	char* tokens_arr[256];
	int i = 0, j = 0;
	printf("%s\n", "Scrie textul:");
	//%[^\n]s -> scanset; take input until newline found, counts in spaces too;
	if (scanf("%[^\n]s", str) != NULL) {
		token = strtok(str, " ");
		while (token != NULL)
		{
			j++;
			tokens_arr[i++] = token;
			token = strtok(NULL, " ");
		}
		sort(tokens_arr, j);
		for (i = 0; i < j; i++) {
			printf("%s\n", tokens_arr[i]);
		}
	}
	else {
		
		printf("%s\n", "       `____________________");
		printf("%s\n", "      `/                    \\ ");
		printf("%s\n", "      |n-ai introdus nimic:/|");
		printf("%s\n", "      |                     /");
		printf("%s\n", "       \\___________________/");
		printf("%s\n", "          \\");
		printf("%s\n", "           \\");
		printf("%s\n", "            \\");
		printf("%s\n", "       ,____ \\        .-;'");
		printf("%s\n", "       `''-.\\ _...._ /`.` ");
		printf("%s\n", "     ,	   \\          / ");
		printf("%s\n", " .-' ',    / ()   () \\;   ");
		printf("%s\n", " `'._  \\  /()    .  (|    ");
		printf("%s\n", "     > .' ;,    -'-  /   ");
		printf("%s\n", "    / <   |;,     __.;");
		printf("%s\n", "    '-.'-.|  ,\\    ,\\ ");
		printf("%s\n", "       `>.|;,\\_)   \\_)");
		printf("%s\n", "        `-;     ,   /");
		printf("%s\n", "          \\    /   < ");
		printf("%s\n", "           '. <`'-,_)");
		printf("%s\n","             '._)");
		return -1;
	}//am stat un pic la asta n-am sa mint
	return 0;
}

//ex4
/*

#include <iostream>
using namespace std;


bool isPrime(int n)
{
	for (int tr = 2; tr < n / 2; tr++)
		if ((n % tr ) == 0)
			return false;
	return true;
}

int main()
{
	int n;
	std::cout << "Enter a number:";
	std::cin >> n;
	if (isPrime(n))
		std::cout << n << " is prime !";
	else
		std::cout << n << " is NOT prime !";

	return 0;

}
*/