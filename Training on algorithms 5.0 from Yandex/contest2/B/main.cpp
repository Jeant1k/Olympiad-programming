#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i)
        cin >> prices[i];
    
    int max_profit = 0;
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < min(i + k + 1, n); ++j)
            max_profit = max(max_profit, prices[j] - prices[i]);
        
    cout << max_profit << endl;

    return 0;

}