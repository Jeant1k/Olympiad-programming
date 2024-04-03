#include <iostream>
#include <set>

using namespace std;

int main() {

    int n;
    cin >> n;

    set<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    set<pair<int, int>> used;

    int perimeter = 0;
    int x, y;
    while (n--) {
        cin >> x >> y;
        for (auto& dir : dirs) {
            if (used.find({x + dir.first, y + dir.second}) == used.end())
                ++perimeter;
            else --perimeter;
        }
        used.insert({x, y});
    }

    cout << perimeter << endl;

    return 0;

}