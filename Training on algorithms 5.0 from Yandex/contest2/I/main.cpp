#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <climits>

using namespace std;

int main() {

    int n;
    cin >> n;

    int r, c;
    vector<int> rows(n, 0);
    vector<int> columns(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> r >> c;
        --r; --c;
        ++rows[r];
        ++columns[c];
    }

    vector<int> target_columns;
    int min_count = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < i; ++j) count += columns[j] * (i - j);
        for (int j = i + 1; j < n; ++j) count += columns[j] * (j - i);
        if (count < min_count) {
            target_columns.clear();
            target_columns.push_back(i);
            min_count = count;
        } else if (count == min_count) {
            target_columns.push_back(i);
        }
    }

    int min_result = INT_MAX;
    for (int target_column : target_columns) {

        int result = 0;
        for (int i = 0; i < columns.size(); ++i) {
            result += columns[i] * abs(target_column - i);
        }

        queue<int> zeros;
        queue<int> stock;
        for (int i = 0; i < rows.size(); ++i) {
            if (rows[i] == 0) {
                zeros.push(i);
            } else if (rows[i] > 1) {
                for (int j = 0; j < rows[i] - 1; ++j)
                    stock.push(i);
            }
            while (!zeros.empty() && !stock.empty()) {
                result += abs(zeros.front() - stock.front());
                zeros.pop();
                stock.pop();
            }
        }

        min_result = min(min_result, result);

    }

    cout << min_result << endl;

    return 0;

}