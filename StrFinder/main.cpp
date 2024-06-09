#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ������� ���-������� (��� �������)
int hash_function(const string& s) {
    int hash = 0;
    for (char c : s) {
        hash += int(c);
    }
    return hash;
}

// �������� ������-�����
int rabin_karp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    int pattern_hash = hash_function(pattern);

    for (int i = 0; i <= n - m; ++i) {
        int sub_hash = hash_function(text.substr(i, m));
        if (sub_hash == pattern_hash) {
            if (text.substr(i, m) == pattern) {
                return i; // ��������� ������� �� ������� i
            }
        }
    }

    return -1; // ��������� �� �������
}



int main() {
    string text = "abracadabra";
    string pattern = "cad";

    int index = rabin_karp(text, pattern);

    setlocale(LC_ALL, "Russian");
    if (index != -1) {
        cout << "��������� ������� �� �������: " << index << endl;
    }
    else {
        cout << "��������� �� �������." << endl;
    }

    return 0;
}