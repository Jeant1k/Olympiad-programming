#include <iostream>

using namespace std;

int main() {

    int m, n;
    cin >> m >> n;

    double a, M1 = 0;
    while (m--) {
        cin >> a;
        M1 += (1 + a) / 2;
    }

    double b, M2 = 0;
    while (n--) {
        cin >> b;
        M2 += (1 + b) / 2;
    }

    if (M1 > M2) cout << "ALICE" << endl;
    else if (M2 > M1) cout << "BOB" << endl;
    else cout << "TIED" << endl;

    return 0;

}
