#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    int a;
    vector<int> counts(10e5, 0);
    while (n--) {
        cin >> a;
        ++counts[a];
    }

    int pair_max = 0, sum = counts[0];
    for (int i = 1; i < 10e5; ++i) {
        sum += counts[i];
        pair_max = max(pair_max, counts[i - 1] + counts[i]);
    }

    cout << sum - pair_max << endl;

    return 0;

}