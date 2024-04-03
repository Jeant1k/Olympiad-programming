#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    std::vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        if (h[i] >= h[i-1]) {
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = 1;
        }
    }

    int max_len = *std::max_element(dp.begin(), dp.end());
    int cuts = n - max_len;

    std::cout << cuts << std::endl;

    return 0;
}
