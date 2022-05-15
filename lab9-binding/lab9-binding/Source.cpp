#include <iostream>
#include <vector>
#include <map>

template <class T, class Y>
struct pair {
    T key;
    Y value;
};

template <class T, class Y>
class Iterator {

    struct tuple {
        T key;
        Y value;
        int idx;
    };
    int idx;
    pair<T, Y>* ptr;
public:
    Iterator(pair<T, Y>* ptr, int idx) : ptr(ptr), idx(idx) {};
    bool operator!=(Iterator const& other) {
        return ptr != other.ptr;
    }
    Iterator& operator++() { ptr++; idx++; return *this; }
    tuple operator*() { tuple temp; temp.key = ptr->key; temp.value = ptr->value; temp.idx = idx; return temp; }
};

template <class T, class Y>
class Map {
    pair<T, Y> vector[30]{};
    int size;
public:
    Map() {
        size = 0;
    };
    Y& operator[](T key) {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key)
                return vector[i].value;
        vector[size].value = {};
        vector[size].key = key;
        size++;
        return vector[size - 1].value;
    }
    Iterator<T, Y> begin() {
        return { vector, 0 };
    }
    Iterator<T, Y> end() {
        return { vector + size, size };
    }
    void Set(const T& key, const Y& value) {
        vector[size].key = key;
        vector[size].value = value;
        size++;
    }
    bool Get(const T& key, Y& value) {
        for (int i = 0; i < size; i++)
            if (vector[i].key == key) {
                value = vector[i].value;
                return true;
            }
        return false;
    }
    int Count() { return size; }
    bool Delete(const T& key) {
        bool ok = false;
        for (int i = 0; i < size; i++) {
            if (vector[i].key == key) {
                while (i + 1 <= size) { 
                    vector[i] = vector[i+1]; 
                    i++;
                }
                ok = true;
            }
            if (ok) { size--; break; }
        }
        return ok;
    }
    void Clear() {
        for (int i = 0; i < size; i++) {
            vector[i].key = 0;
            vector[i].value = nullptr;
        }
    }
    bool Includes(const Map<T, Y>& map_B) {

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < map_B.size; j++) {
                if (vector[i].key == map_B.vector[j].key) break;
                if (vector[i].key != map_B.vector[j].key && j == map_B.size - 1) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    const char* valoare;
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m[20] = "result";

    std::cout << '\n';
    for (auto [key, value, index] : m) {

        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    int test_key = 20;
    if (m.Get(test_key, valoare))
        printf("Key %d is included in map.\n", test_key);
    else printf("Key %d is NOT included in map.\n", test_key);
    
    std::cout << '\n';
    Map<int, const char*> m_B;
    m_B[30] = "C++";
    m_B[20] = "test";
    m_B[10] = "Poo";
    if (m.Includes(m_B))
        std::cout << "First map is included in parameter map." << '\n';
    else std::cout << "First map is NOT included parameter map" << '\n';

    std::cout << '\n';
    m.Delete(10);
    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }

    m.Set(10, "C++");
    m.Delete(30);

    std::cout << std::endl;

    for (auto [key, value, index] : m) {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    
    std::cout << std::endl;
    if (m_B.Includes(m))
        std::cout << "First map is included parameter map." << '\n';
    else std::cout << "First map is NOT included parameter map" << '\n';

    return 0;
}