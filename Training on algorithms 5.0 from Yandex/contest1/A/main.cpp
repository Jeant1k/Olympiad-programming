#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int p, v, q, m;
    cin >> p >> v >> q >> m;

    int vl = p - v, vr = p + v;
    int ml = q - m, mr = q + m;

    int count = vr - vl + 1 + mr - ml + 1;
    if (ml <= vr && vl <= mr)
        count = max(vr, mr) - min(vl, ml) + 1;
    
    cout << count << endl;

    return 0;
}
