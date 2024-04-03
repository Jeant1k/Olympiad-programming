#include <iostream>

using namespace std;

int main() {

    int k;
    cin >> k;

    int x, y;
    int min_x = 1000000001, max_x = 0, min_y = 1000000001, max_y = 0;
    while (k--) {
        cin >> x >> y;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
    }

    cout << min_x << ' ' << min_y << ' ' << max_x << ' ' << max_y << endl;

    return 0;
}