#define _CRT_SECURE_NO_WARNINGS
#include "Json.h"

NumberValue::NumberValue(long long x) {
	value = x;
}

void NumberValue::print(std::ostream& out) {
	out << value;
}

StringValue::StringValue(const char* x) {
	int i = 0;
	while (x[i] != '\0') {
		value[i] = x[i];
		i++;
	}
	value[i] = '\0';
}

void StringValue::print(std::ostream& out) {
	int i = 0;
	out << value << " ";
}

BoolValue::BoolValue(bool x) {
	value = x;
}

void BoolValue::print(std::ostream& out) {
	out << value;
}

NullValue::NullValue()
{
}

void NullValue::print(std::ostream& out) {
}

ArrayValue::ArrayValue() {
	size = 0;
}

void ArrayValue::add(JsonValue* value) {
	if (size < 16) {
		values[size] = value;
		++size;
	}
}

void ArrayValue::print(std::ostream& out) {
	int i = 0;
	for (i = 0; i < size; i++) {
		out << values[i];
	}
}

ObjectValue::ObjectValue() {
	size = 0;
}

void ObjectValue::add(const char* name, JsonValue* value) {
	strcpy(values[size].name, name);
	values[size].value = value;
	size++;
}

void ObjectValue::print(std::ostream& out) {

	for (unsigned i = 0; i < size; ++i) {
		out << values[i].name;
		values[i].value->print(out);
	}
}

JsonValue::~JsonValue()
{
}
