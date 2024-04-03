#include <iostream>
#include <climits>

using namespace std;


int main() {

    int x, y, p;
    cin >> x >> y >> p;
    
    int count = 1, min_count = INT_MAX;
    y -= x;
    int k = p;

    // cout << count << ": x = " << x << " k = " << k << " y = " << y << endl;

    int prev_x = x, prev_k = k, prev_y = y;
    while (x > 0 && k > 0 && y > 0 && count < min_count) {
        if (x > y) {
            int tmp_x = x - (k - (x - y)), tmp_k = k - (x - y);
            int tmp_count = count + 1;
            // cout << "Try " << tmp_count << ": x = " << tmp_x << " k = " << tmp_k << " y = " << 0 << endl;
            while (tmp_x > 0 && tmp_k > 0) {
                tmp_k -= tmp_x;
                tmp_x -= tmp_k;
                ++tmp_count;
                // cout << "Try " << tmp_count << ": x = " << tmp_x << " k = " << tmp_k << " y = " << 0 << endl;
            }
            if (tmp_x > 0 && tmp_count < min_count) {
                min_count = tmp_count;
            }
        }
        y -= (x >= k ? x - k : 0);
        k = x >= k ? 0 : k - x;
        x -= k;
        k += p;
        ++count;

        // cout << count << ": x = " << x << " k = " << k << " y = " << y << endl;

        if (x == prev_x && k == prev_k && y == prev_y) {
            if (min_count == INT_MAX) min_count = -1;
            count = INT_MAX;
            break;
        }
    }

    if (x > 0 && count < min_count)
        min_count = count;

    if (min_count == INT_MAX)
        min_count = -1;

    cout << min_count << endl;

    return 0;
    
}
