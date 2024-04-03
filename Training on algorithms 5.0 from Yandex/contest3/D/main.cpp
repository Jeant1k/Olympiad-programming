#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    int a;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    unordered_set<int> window;
    for (int i = 0; i < n; ++i) {
        // cout << "window: ";
        // for (auto& w : window) cout << w << ' ';
        // cout << endl;
        if (i > k) { window.erase(numbers[i - k - 1]); }
        if (window.find(numbers[i]) != window.end()) {
            cout << "YES" << endl;
            return 0;
        }
        window.insert(numbers[i]);
    }

    cout << "NO" << endl;
    
    return 0;

}