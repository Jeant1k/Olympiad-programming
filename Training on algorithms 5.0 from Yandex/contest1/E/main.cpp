#include <iostream>
#include <string>

using namespace std;

int main() {

    long long n;
    int k, d;
    cin >> n >> k >> d;

    int i;
    for (i = 0; i < 10; ++i) {
        if ((n * 10 + i) % k == 0) {
            n = n * 10 + i;
            break;
        }
    }

    if (i == 10) {
        cout << -1 << endl;
        return 0;
    }

    string result = to_string(n) + string(d - 1, '0');

    cout << result << endl;

    return 0;
}
