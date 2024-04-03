#include <iostream>
#include <string>

using namespace std;

int main() {

    string g11, g12, g21, g22;
    getline(cin, g11, ':');
    getline(cin, g12);
    getline(cin, g21, ':');
    getline(cin, g22);

    int flag;
    cin >> flag;

    pair<int, int> first = {stoi(g11), stoi(g12)};
    pair<int, int> second = {stoi(g21), stoi(g22)};

    int count = first.second + second.second - first.first - second.first;

    if (count < 0) {
        cout << 0 << endl;
        return 0;
    }

    if (flag == 1 && count + second.first <= first.second) ++count;
    if (flag == 2 && first.first <= second.second) ++count;

    cout << count << endl;

    return 0;
}
