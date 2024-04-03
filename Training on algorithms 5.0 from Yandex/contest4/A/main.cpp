#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int binarySearch(vector<int>& numbers, int target, function<bool(int, int)> compare) {
    int l = 0, r = numbers.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (compare(numbers[m], target)) l = m + 1;
        else r = m;
    }
    return l;
}

int main() {

    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i)
        cin >> numbers[i];
    
    sort(numbers.begin(), numbers.end());

    int k;
    cin >> k;

    int l, r;
    while (k--) {

        cin >> l >> r;

        int l_i = binarySearch(numbers, l, [](const int& a, const int& b) {
            return a < b;
        });

        int r_i = binarySearch(numbers, r, [](const int& a, const int& b) {
            return a <= b;
        });

        cout << r_i - l_i << ' ';

    }

    cout << endl;

    return 0;

}
