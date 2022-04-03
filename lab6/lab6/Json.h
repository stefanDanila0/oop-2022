#pragma once
#include <iostream>


struct JsonValue {
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out) = 0;
};

struct NumberValue : JsonValue {
    long long value;
    NumberValue(long long x);
    void print(std::ostream& out) override;
};

struct StringValue : JsonValue {
    char value[256];
    StringValue(const char* x);
    void print(std::ostream& out) override;
};

struct BoolValue : JsonValue {
    bool value;
    BoolValue(bool x);
    void print(std::ostream& out) override;
};

struct NullValue : JsonValue {
    NullValue();
    void print(std::ostream& out) override;
};

struct ArrayValue : JsonValue {
    JsonValue* values[16];
    unsigned size;
    ArrayValue();

    void add(JsonValue* value);
    void print(std::ostream& out) override;
};

struct ObjectValue : JsonValue {
    struct Pair {
        char name[256];
        JsonValue* value;
    };
    Pair values[16];
    unsigned size;

    ObjectValue();

    void add(const char* name, JsonValue* value);
    void print(std::ostream& out) override;
};
