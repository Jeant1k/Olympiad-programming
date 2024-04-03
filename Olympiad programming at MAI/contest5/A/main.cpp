#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double n, t, m, x, y;
    cin >> n >> t >> m >> x >> y;

    t *= 60;

    double t1 = m / x;
    double t2 = (n - m) / y;

    double delta = t - (t1 + t2);

    if (delta < 0) cout << ceil((-delta) / 60.0) << endl;
    else cout << 0 << endl;

    return 0;

}
