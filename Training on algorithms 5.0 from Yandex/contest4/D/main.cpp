#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int countLines(const vector<int>& a, int w) {

    int count = 1, len = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] > w) {
            count = -1;
            break;
        }
        len += a[i] + 1;
        if (len - 1 > w) {
            len = a[i] + 1;
            ++count;
        }
    }

    // cout << "width = " << w << " count = " << count << endl;
    return count;

}

bool check(const vector<int>& a, const vector<int>& b, int m, int w) {

    int mCount1 = countLines(a, m);
    int mCount2 = countLines(b, w - m);
    int mEpsCount1 = countLines(a, m + 1);
    int mEpsCount2 = countLines(b, w - m - 1);
    int diff1 = abs(mCount1 - mCount2);
    int diff2 = abs(mEpsCount1 - mEpsCount2);

    cout << "diff1 = " << diff1 << " diff2 = " << diff2 << endl;
    
    if (mCount1 == -1 || mEpsCount1 == -1) return false;
    if (mCount2 == -1 || mEpsCount2 == -1) return true;

    return diff1 <= diff2;

}

int binarySearch(int w, const vector<int>& a, const vector<int>& b) {

    int l = 0, r = w;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        cout << endl << "m = " << m << endl;
        if (check(a, b, m, w)) {
            r = m;
        } else {
            l = m;
        }
        cout << "left = " << l << " right = " << r << endl;
    }

    int min_len = 1000000;
    for (int i = l; i <= r; ++i) {
        int c1 = countLines(a, i);
        int c2 = countLines(b, w - i);
        if (c1 != -1 && c2 != -1)
            min_len = min(min_len, max(c1, c2));
    }

    return min_len;

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, n, m;
    cin >> w >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    cout << binarySearch(w, a, b) << endl;
    
    return 0;

}
