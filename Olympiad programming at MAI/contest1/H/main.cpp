#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll score(ll a, ll b, ll c) {
    return a * a + b * b + c * c + 7 * min({a, b, c});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        vector<ll> tokens(4);
        for (int i = 0; i < 4; i++) cin >> tokens[i];

        vector<ll> answers = {
            score(tokens[0] + tokens[3], tokens[1], tokens[2]),
            score(tokens[0], tokens[1] + tokens[3], tokens[2]),
            score(tokens[0], tokens[1], tokens[2] + tokens[3])
        };

        if (tokens[3] % 2 == 0) {
            answers.push_back(score(tokens[0] + tokens[3] / 2, tokens[1] + tokens[3] / 2, tokens[2]));
            answers.push_back(score(tokens[0] + tokens[3] / 2, tokens[1], tokens[2] + tokens[3] / 2));
            answers.push_back(score(tokens[0], tokens[1] + tokens[3] / 2, tokens[2] + tokens[3] / 2));
        } else {
            answers.push_back(score(tokens[0] + tokens[3] / 2 + 1, tokens[1] + tokens[3] / 2, tokens[2]));
            answers.push_back(score(tokens[0] + tokens[3] / 2, tokens[1] + tokens[3] / 2 + 1, tokens[2]));
            answers.push_back(score(tokens[0] + tokens[3] / 2 + 1, tokens[1], tokens[2] + tokens[3] / 2));
            answers.push_back(score(tokens[0] + tokens[3] / 2, tokens[1], tokens[2] + tokens[3] / 2 + 1));
            answers.push_back(score(tokens[0], tokens[1] + tokens[3] / 2 + 1, tokens[2] + tokens[3] / 2));
            answers.push_back(score(tokens[0], tokens[1] + tokens[3] / 2, tokens[2] + tokens[3] / 2 + 1));
        }

        if (tokens[3] % 3 == 0) {
            answers.push_back(score(tokens[0] + tokens[3] / 3, tokens[1] + tokens[3] / 3, tokens[2] + tokens[3] / 3));
        } else if (tokens[3] % 3 == 1) {
            answers.push_back(score(tokens[0] + tokens[3] / 3 + 1, tokens[1] + tokens[3] / 3, tokens[2] + tokens[3] / 3));
            answers.push_back(score(tokens[0] + tokens[3] / 3, tokens[1] + tokens[3] / 3 + 1, tokens[2] + tokens[3] / 3));
            answers.push_back(score(tokens[0] + tokens[3] / 3, tokens[1] + tokens[3] / 3, tokens[2] + tokens[3] / 3 + 1));
        } else {
            answers.push_back(score(tokens[0] + tokens[3] / 3 + 1, tokens[1] + tokens[3] / 3 + 1, tokens[2] + tokens[3] / 3));
            answers.push_back(score(tokens[0] + tokens[3] / 3 + 1, tokens[1] + tokens[3] / 3, tokens[2] + tokens[3] / 3 + 1));
            answers.push_back(score(tokens[0] + tokens[3] / 3, tokens[1] + tokens[3] / 3 + 1, tokens[2] + tokens[3] / 3 + 1));
        }

        cout << *max_element(answers.begin(), answers.end()) << endl;
    }

    return 0;
}
