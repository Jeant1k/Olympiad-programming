#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    cin >> n;

    int a, b;
    vector<pair<pair<int, int>, int>> positive;
    vector<pair<pair<int, int>, int>> non_positive;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (a - b > 0) positive.push_back({{a, b}, i + 1});
        else non_positive.push_back({{a, b}, i + 1});
    }

    int max_pos_down = -1, max_pos_idx = -1;
    for (int i = 0; i < positive.size(); ++i) {
        if (positive[i].first.second > max_pos_down) {
            max_pos_down = positive[i].first.second;
            max_pos_idx = i;
        }
    }

    int max_npos_up = -1, max_npos_idx = -1;
    for (int i = 0; i < non_positive.size(); ++i) {
        if (non_positive[i].first.first > max_npos_up) {
            max_npos_up = non_positive[i].first.first;
            max_npos_idx = i;
        }
    }

    vector<int> indexes;
    long long max_height = 0;
    for (int i = 0; i < positive.size(); ++i) {
        if (i == max_pos_idx) continue;
        max_height += (positive[i].first.first - positive[i].first.second);
        indexes.push_back(positive[i].second);
    }

    if (max_pos_idx != -1 && max_npos_idx != -1) {
        max_height += max(positive[max_pos_idx].first.first, positive[max_pos_idx].first.first - max_pos_down + max_npos_up);
        indexes.push_back(positive[max_pos_idx].second);
        indexes.push_back(non_positive[max_npos_idx].second);
    } else if (max_pos_idx != -1) {
        max_height += positive[max_pos_idx].first.first;
        indexes.push_back(positive[max_pos_idx].second);
    } else if (max_npos_idx != -1) {
        max_height += max_npos_up;
        indexes.push_back(non_positive[max_npos_idx].second);
    }

    cout << max_height << endl;
    for (int i : indexes)
        cout << i << ' ';

    for (int i = 0; i < non_positive.size(); ++i) {
        if (i == max_npos_idx) continue;
        cout << non_positive[i].second << ' ';
    }

    cout << endl;

    return 0;
    
}