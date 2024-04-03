#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int binarySearch(const vector<ull>& nums, int l, ull s) {

    int left = 0, right = nums.size() - 1;
    while (left < right) {

        int mid = (left + right) / 2;
        ull prevSum = mid - l >= 0 ? nums[mid - l] : 0;

        if (nums[mid] - prevSum < s) left = mid + 1;
        else right = mid;

    }

    ull prevSum = left - l >= 0 ? nums[left - l] : 0;
    if (nums[left] - prevSum != s) return -1;

    return left - l + 2;

}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<ull> rgt(n);
    for (int i = 0; i < n; ++i) {
        cin >> rgt[i];
        if (i > 0) rgt[i] += rgt[i - 1];
    }

    int l;
    ull s;
    while (m--) {
        cin >> l >> s;
        cout << binarySearch(rgt, l, s) << endl;
    }

    return 0;

}
