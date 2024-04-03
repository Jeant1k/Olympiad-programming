#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

bool check(ll m, ll n) {
    ll count = (5 * m + m * m * m + 6 * m * m) / 6 - 1;
    return count <= n;
}

ll count1(ll n) {
    ll count = (5 * n + n * n * n + 6 * n * n) / 6 - 1;
    return count;
}

ll count2(ll n) {
    ll count = 0;
    for (ll i = n, j = 1; i > 0; --i, ++j) {
        count += (i + 1) * j;
    }
    return count - 1;
}

ll binarySearch(ll l, ll r, ll n) {
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m, n)) l = m;
        else r = m - 1;
    }
    return l;
}

int main() {

    ll n;
    cin >> n;

    if (n == 0 || n == 1) {
        cout << n << endl;
        return 0;
    }

    cout << binarySearch(0, n / 2, n) << endl;
    

    return 0;

}
