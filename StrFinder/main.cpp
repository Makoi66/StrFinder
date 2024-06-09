#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//  простая хеш-функция (для примера) *с учетом предыдущего хеша*
int hash_function(const string& s, int prime = 101) {
    int hash = 0;
    for (char c : s) {
        hash = (hash * prime + int(c));
        //cout << hash << endl;
    }
    //cout << endl;
    return hash;
}

int recalculate_hash(const string& s, int old_index, int new_index, int old_hash, int pattern_length, int prime = 101) {
    //cout << old_hash << " " << int(s[old_index]) * pow(prime, pattern_length - 1) << " ";
    int new_hash = old_hash - int(s[old_index]) * pow(prime, pattern_length - 1);
    //cout << new_hash << " ";
    new_hash = new_hash * prime + int(s[new_index]);
    //cout << new_hash << endl << endl;
    return new_hash;
}

// Алгоритм Рабина-Карпа
int rabin_karp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int prime = 101; // простое число для хеш-функции

    int pattern_hash = hash_function(pattern, prime);
    int text_hash = hash_function(text.substr(0, m), prime);
    //cout << "old_hash  -  new_hash   new_hash+" << endl;

    for (int i = 0; i <= n - m; ++i) {
        if (pattern_hash == text_hash) {
            if (text.substr(i, m) == pattern) {
                return i;
            }
        }

        if (i < n - m) {
            text_hash = recalculate_hash(text, i, i + m, text_hash, m, prime);
        }
    }

    return -1;
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
