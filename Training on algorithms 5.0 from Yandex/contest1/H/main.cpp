#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {

    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;

    double t1 = __DBL_MAX__, t2 = __DBL_MAX__, t3 = __DBL_MAX__,
           t4 = __DBL_MAX__, t5 = __DBL_MAX__, t6 = __DBL_MAX__,
           t7 = __DBL_MAX__, t8 = __DBL_MAX__;

    cout << fixed << setprecision(10);

    if (x1 == x2) {
        cout << "YES" << endl << 0. << endl;
        return 0;
    }

    if (v1 + v2 != 0) {
        t1 = (L - x1 - x2) / (v1 + v2);
        t3 = (2 * L - x1 - x2) / (v1 + v2);
        t6 = (-x1 - x2) / (v1 + v2);
    }
    if (v2 - v1 != 0) {
        t2 = (x1 - x2) / (v2 - v1);
        t4 = (2 * L + x1 - x2) / (v2 - v1);
        t7 = (L - x2 + x1) / (v2 - v1);
    }
    if (v1 - v2 != 0) {
        t5 = (2 * L + x2 - x1) / (v1 - v2);
        t8 = (L - x1 + x2) / (v1 - v2);
    }

    // cout << "t1 = " << t1 << endl << "t2 = " << t2 << endl << "t3 = " << t3 << endl;
    // cout << "t4 = " << t4 << endl << "t5 = " << t5 << endl << "t6 = " << t6 << endl;
    // cout << "t7 = " << t7 << endl << "t8 = " << t8 << endl;

    if (t1 < 0) t1 = __DBL_MAX__;
    if (t2 < 0) t2 = __DBL_MAX__;
    if (t3 < 0) t3 = __DBL_MAX__;
    if (t4 < 0) t4 = __DBL_MAX__;
    if (t5 < 0) t5 = __DBL_MAX__;
    if (t6 < 0) t6 = __DBL_MAX__;
    if (t7 < 0) t7 = __DBL_MAX__;
    if (t8 < 0) t8 = __DBL_MAX__;

    if (t1 == __DBL_MAX__ && t2 == __DBL_MAX__ && t3 == __DBL_MAX__ &&
        t4 == __DBL_MAX__ && t5 == __DBL_MAX__ && t6 == __DBL_MAX__ &&
        t7 == __DBL_MAX__ && t8 == __DBL_MAX__)
        cout << "NO" << endl;
    else
        cout << "YES" << endl << min({t1, t2, t3, t4, t5, t6, t7, t8}) << endl;

    return 0;
}
