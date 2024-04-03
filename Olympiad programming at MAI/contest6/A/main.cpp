#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {

    int p, m;
    cin >> p >> m;

    if (p > m) swap(p, m);

    vector<pair<int, int>> cases(3);

    cases[0] = make_pair(p - 1 - 12, p - 1);
    cases[1] = make_pair(m - 1 - p, m - 1);
    cases[2] = make_pair(24 - m, 24);

    sort(cases.begin(), cases.end(), compare);
    
    cout << cases[0].second << endl;

    return 0;
    
}
