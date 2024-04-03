#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());

    int k;
    long long l, r, m;
    while (q--) {
        cin >> k;
        l = 0, r = INT_MAX;
        while (r - l > 1) {
            m = (l + r) / 2;
            if (m - (lower_bound(a.begin(), a.end(), m) - a.begin()) < k) l = m;
            else r = m;
        }
        cout << l << ' ';
    }
    cout << endl;

    return 0;

}
