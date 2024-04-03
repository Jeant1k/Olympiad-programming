#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    int k;
    string song;
    unordered_map<string, int> songs;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        while (k--) {
            cin >> song;
            ++songs[song];
        }
    }

    vector<string> playlist;
    for (auto& s : songs) {
        if (s.second == n)
            playlist.push_back(s.first);
    }

    sort(playlist.begin(), playlist.end());

    cout << playlist.size() << endl;
    for (string song : playlist)
        cout << song << ' ';
    cout << endl;

    return 0;

}