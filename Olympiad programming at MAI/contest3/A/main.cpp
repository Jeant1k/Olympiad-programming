#include <vector>
#include <fstream>

using namespace std;

int main() {

    ifstream in("alter.in");
    ofstream out("alter.out");

    int n, m;
    in >> n >> m;

    vector<vector<int>> result;

    if (n < m) {
        for (int i = 2; i <= n; i += 2)
            result.push_back({i, 1, i, m});
        for (int i = 2; i <= m; i += 2)
            result.push_back({1, i, n, i});
    } else {
        for (int i = 2; i <= m; i += 2)
            result.push_back({1, i, n, i});
        for (int i = 2; i <= n; i += 2)
            result.push_back({i, 1, i, m});
    }

    out << result.size() << endl;
    for (auto& r : result)
        out << r[0] << ' ' << r[1] << ' ' << r[2] << ' ' << r[3] << endl;

    return 0;
}
