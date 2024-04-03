#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    
    int n;
    cin >> n;
    vector<pll> points(n);
    unordered_map<ll, unordered_map<ll, bool>> point_map;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        point_map[points[i].first][points[i].second] = true;
    }

    vector<pll> to_add;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            pll p1 = points[i], p2 = points[j];
            pll p3 = make_pair(p1.first + (p2.second - p1.second), p1.second - (p2.first - p1.first));
            pll p4 = make_pair(p2.first + (p2.second - p1.second), p2.second - (p2.first - p1.first));
            if (!point_map[p3.first][p3.second]) {
                to_add.push_back(p3);
                point_map[p3.first][p3.second] = true;
            }
            if (!point_map[p4.first][p4.second]) {
                to_add.push_back(p4);
                point_map[p4.first][p4.second] = true;
            }
        }
    }

    cout << to_add.size() << endl;
    for (auto& p : to_add) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
