#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a;
    long long count = 0;
    while (n--) {
        cin >> a;
        count += (a / 4);
        a %= 4;
        if (a == 3) count += 2;
        else count += a;
    }

    cout << count << endl;

    return 0;
}
