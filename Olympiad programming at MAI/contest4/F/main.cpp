#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> square(n, vector<int>(n));
    vector<int> rows_sum(n);
    vector<int> columns_sum(n);
    int total_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> square[i][j];
            rows_sum[i] += square[i][j];
            columns_sum[j] += square[i][j];
            total_sum += square[i][j];
        }
    }

    int magic_constant = total_sum / n;

    auto min_rows_sum = min_element(rows_sum.begin(), rows_sum.end());
    auto max_rows_sum = max_element(rows_sum.begin(), rows_sum.end());
    auto min_columns_sum = min_element(columns_sum.begin(), columns_sum.end());
    auto max_columns_sum = max_element(columns_sum.begin(), columns_sum.end());

    pair<int, int> res1, res2;

    if (*min_rows_sum == *min_columns_sum && *max_rows_sum == *max_columns_sum) {
        res1 = make_pair(min_rows_sum - rows_sum.begin() + 1, min_columns_sum - columns_sum.begin() + 1);
        res2 = make_pair(max_rows_sum - rows_sum.begin() + 1, max_columns_sum - columns_sum.begin() + 1);
    } else if (min_columns_sum == max_columns_sum) {
        for (int i = 0; i < n; ++i) {
            if (*min_rows_sum - *max_rows_sum == 2 * square[min_rows_sum - rows_sum.begin()][i] - 2 * square[max_rows_sum - rows_sum.begin()][i]) {
                res1 = make_pair(min_rows_sum - rows_sum.begin() + 1, i + 1);
                res2 = make_pair(max_rows_sum - rows_sum.begin() + 1, i + 1);
            }
        }
    } else if (min_rows_sum == max_rows_sum) {
        for (int i = 0; i < n; ++i) {
            if (*min_columns_sum - *max_columns_sum == 2 * square[i][min_columns_sum - columns_sum.begin()] - 2 * square[i][max_columns_sum - columns_sum.begin()]) {
                res1 = make_pair(i + 1, min_columns_sum - columns_sum.begin() + 1);
                res2 = make_pair(i + 1, max_columns_sum - columns_sum.begin() + 1);
            }
        }
    }

    if (res1 > res2) swap(res1, res2);

    cout << res1.first << ' ' << res1.second << endl;
    cout << res2.first << ' ' << res2.second << endl;

    return 0;

}
