#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a;
    priority_queue<pair<int, pair<int, int>>> grid;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a;
            grid.push({a, {i, j}});
        }
    }

    pair<int, int> result = {-1, -1};
    pair<int, int> max1, max2;
    max1 = grid.top().second;
    grid.pop();
    // cout << "max1 = " << max1.first << ' ' << max1.second << endl;
    max2 = grid.top().second;
    grid.pop();
    // cout << "max2 = " << max2.first << ' ' << max2.second << endl;

    if (max1.first != max2.first && max1.second != max2.second) {
        while (true) {
            if (max1.first == grid.top().second.first) {
                result = {max1.first, max2.second};
                break;
            }
            if (max2.first == grid.top().second.first) {
                result = {max2.first, max1.second};
                break;
            }
            if (max1.second == grid.top().second.second) {
                result = {max2.first, max1.second};
                break;
            }
            if (max2.second == grid.top().second.second) {
                result = {max1.first, max2.second};
                break;
            }
            grid.pop();
        }
    } else if (max1.first == max2.first) {
        result.first = max1.first;
        while (true) {
            if (max1.first != grid.top().second.first) {
                result = {max1.first, grid.top().second.second};
                break;
            }
            grid.pop();
        }
    } else if (max1.second == max2.second) {
        while (true) {
            if (max1.second != grid.top().second.second) {
                result = {grid.top().second.first, max1.second};
                break;
            }
            grid.pop();
        }
    }
    
    cout << result.first + 1 << ' ' << result.second + 1 << endl;
    
    return 0;

}