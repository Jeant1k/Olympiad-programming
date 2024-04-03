#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> towers(n);
    for (int i = 0; i < n; ++i)
        cin >> towers[i];
    
    sort(towers.begin(), towers.end());
    
    int result = towers[n / 2];
    for (int i = n / 2; i < n - 1 && k > 0; ++i) {
        int needed = (towers[i + 1] - result) * (i + 1 - n / 2);
        // cout << needed << endl;
        if (needed <= k) {
            k -= needed;
            result = towers[i + 1];
        } else {
            while (k > 0) {
                k -= (i + 1 - n / 2);
                result += k >= 0 ? 1 : 0;
            }
            break;
        }
    }

    while (k > 0) {
        k -= (n - n / 2);
        result += k >= 0 ? 1 : 0;
    }

    cout << result << endl;

    return 0;
    
}
