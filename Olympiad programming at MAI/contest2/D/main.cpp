#include <bits/stdc++.h>

using namespace std;

int main() {

    string dna;
    cin >> dna;
    vector<vector<int>> counts(dna.size(), vector<int>(4, 0));
    for (int i = 0; i < dna.size(); ++i) {
        if (i > 0)
            for (int j = 0; j < 4; ++j)
                counts[i][j] = counts[i - 1][j];

        if (dna[i] == 'A')  ++counts[i][0];
        else if (dna[i] == 'T')  ++counts[i][1];
        else if (dna[i] == 'G')  ++counts[i][2];
        else if (dna[i] == 'C')  ++counts[i][3];
    }

    int m;
    cin >> m;
    while (m--) {
        int s, e;
        cin >> s >> e;
        --s; --e;
        vector<pair<int, char>> frequency;
        for (int i = 0; i < 4; ++i) {
            int c = counts[e][i] - (s > 0 ? counts[s - 1][i] : 0);
            frequency.push_back({-c, "ATGC"[i]});
        }

        stable_sort(frequency.begin(), frequency.end(),
                    [](const pair<int, char>& a, const pair<int, char>& b) {
            return a.first < b.first;
        });

        for (auto& f : frequency) cout << f.second;
        cout << endl;
    }

    return 0;
}
