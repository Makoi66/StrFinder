#include <iostream>
#include <string>
#include <vector>

using namespace std;

// простая хеш-функция (для примера)
int hash_function(const string& s) {
    int hash = 0;
    for (char c : s) {
        hash += int(c);
    }
    return hash;
}

// алгоритм Рабина-Карпа
int rabin_karp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int pattern_hash = hash_function(pattern);

    for (int i = 0; i <= n - m; ++i) {
        int sub_hash = hash_function(text.substr(i, m));
        if (sub_hash == pattern_hash) {
            if (text.substr(i, m) == pattern) {
                return i; // Подстрока найдена на позиции i
            }
        }
    }

    return -1; // Подстрока не найдена
}



int main() {
    string text = "abracadabra";
    string pattern = "cad";

    int index = rabin_karp(text, pattern);

    setlocale(LC_ALL, "Russian");
    if (index != -1) {
        cout << "подстрока найдена на позиции: " << index << endl;
    }
    else {
        cout << "подстрока не найдена." << endl;
    }

    return 0;
}