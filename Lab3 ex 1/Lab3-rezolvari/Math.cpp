#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int Math::Add(int a, int b) {
	return a + b;
}

int Math::Add(int a, int b, int c) {
	return a + b + c;
}

int Math::Add(double a, double b) {
	return (double)(a + b);
}

int Math::Add(double a, double b, double c) {
	return a + b + c;
}

int Math::Mul(int a, int b) {
	return a * b;
}

int Math::Mul(int a, int b, int c) {
	return a * b * c;
}

int Math::Mul(double a, double b) {
	return a * b;
}

int Math::Mul(double a, double b, double c) {
	return a * b * c;
}

int Math::Add(int count, ...) {
	int nr, sum = 0;
	va_list args;
	va_start(args, count);
	for (unsigned int i = 0; i < count; ++i) {
		nr = va_arg(args, int);
		sum += nr;
	}
	return sum;
}

char* Math::Add(const char* a, const char* b) {
	if (a == nullptr || b == nullptr)
		return nullptr;
	int size_a = strlen(a);
	int size_b = strlen(b);
	int size = size_a + size_b;
	char* buffer = (char*)malloc(size-4);
	if (buffer) {
		memcpy(buffer, a, size_a);
		memcpy(&buffer[size_a], b, size_b);
	}
	
	return &buffer[0];
}
