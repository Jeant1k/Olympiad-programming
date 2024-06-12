#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string name;
    int p, e;
    vector<pair<int, string>> scores(n);
    for (int i = 0; i < n; ++i) {
        int score = 0, min_score = 10, max_score = 0;
        cin >> name >> p;
        for (int j = 0; j < 6; ++j) {
            cin >> e;
            score += e;
            min_score = min(min_score, e);
            max_score = max(max_score, e);
        }
        scores[i] = make_pair(score - min_score - max_score + p * 10, name);
    }

    stable_sort(scores.begin(), scores.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first;
    });

    // int c = 0;
    // for (auto& [score, name] : scores) {
    //     cout << "name = " << name << " score = " << score << endl;
    //     ++c;
    //     if (c > 10) break;
    // }

    vector<pair<int, string>> result;
    for (int i = 0; i < n; ++i) {
        if (i > 0 && scores[i].first < scores[i - 1].first && result.size() > 2) break;
        result.push_back(make_pair(scores[i].first, scores[i].second));
    }

    for (auto& [score, name] : result)
        cout << name << ' ' << score << endl;

    return 0;

}
