#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int counts[26] = {0};
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;
        ++counts[c - 'a'];
    }

    int count = 0;

    int n, x;
    cin >> n;
    while (n--) {
        cin >> c >> x;
        count += ceil(counts[c - 'a'] / (x - 1.0));
    }

    for (int i = 0; i < 26; ++i) {
        count += counts[i];
    }

    cout << count << endl;

    return 0;
}
