#include <iostream>
#include <unordered_map>

using namespace std;

long long count_good_pairs(int n, int k) {

    int a;
    long long count = 0;
    unordered_map<int, int> sub;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a < k) {
            if (sub.find(a) != sub.end())
                count += sub[a];
            ++sub[k - a];
        }
    }

    return count;

}

int main() {

    int n, k;
    cin >> n >> k;

    long long count_m = count_good_pairs(n, k),
              count_b = count_good_pairs(n, k);

    // cout << count_m << ' ' << count_b << endl;
    
    if (count_m > count_b) cout << "MAHMOUD" << endl;
    else if (count_b > count_m) cout << "BASHAR" << endl;
    else cout << "DRAW" << endl;

    return 0;

}
