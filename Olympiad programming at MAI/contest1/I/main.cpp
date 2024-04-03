#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<tuple<int, int, int>> apps(n);
    for (int i = 0; i < n; i++) {
        cin >> get<1>(apps[i]) >> get<0>(apps[i]);
        get<2>(apps[i]) = i + 1;
    }

    sort(apps.begin(), apps.end(), [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return max(get<0>(a), get<1>(a)) < max(get<0>(b), get<1>(b));
    });

    vector<int> installed;
    for (auto& app : apps) {
        int space_needed = max(get<0>(app), get<1>(app));
        if (space_needed <= c) {
            c -= get<0>(app);
            installed.push_back(get<2>(app));
        }
    }

    cout << installed.size() << endl;
    for (auto& app : installed) cout << app << ' ';
    cout << endl;
    
    return 0;
}
