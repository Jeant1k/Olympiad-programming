#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    vector<int> count_letters_a(26, 0);
    vector<int> count_letters_b(26, 0);

    for (char c : a)
        ++count_letters_a[tolower(c) - 'a'];
    for (char c : b)
        ++count_letters_b[tolower(c) - 'a'];

    for (int i = 0; i < 26; ++i) {
        if (count_letters_a[i] != count_letters_b[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;

}