#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, pair<int, int>> dirs = {
    {'U', {0, 1}},
    {'D', {0, -1}},
    {'L', {-1, 0}},
    {'R', {1, 0}},
};

int main() {

    int x, y;
    string path;
    cin >> x >> y >> path;

    for (char c : path) {
        auto dir = dirs[c];
        x += dir.first;
        y += dir.second;
    }

    cout << x << ' ' << y << endl;

    return 0;

}
