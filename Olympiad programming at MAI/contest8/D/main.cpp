#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> prefix_sum[i + 1];
        prefix_sum[i + 1] += prefix_sum[i];
    }

    int left = 0, answer = INT_MAX;
    long long cur_sum = 0;
    for (int right = 0; right < n + 1; ++right) {
        cur_sum = prefix_sum[right] - prefix_sum[left];
        while (cur_sum >= x) {
            answer = min(answer, right - left);
            cur_sum = prefix_sum[right] - prefix_sum[++left];
        }
    }

    if (answer == INT_MAX) cout << -1 << endl;
    else cout << answer << endl;

    return 0;

}
