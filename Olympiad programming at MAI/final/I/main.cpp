#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> wood(n);
    for (int i = 0; i < n; ++i) cin >> wood[i];

    if (m >= 5) {
        for (const string& str : wood) {
            for (int i = 0; i <= m - 5; ++i) {
                if (str.substr(i, 5) == "graph") {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    
    if (n >= 5) {
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j <= n - 5; ++j) {
                string str = "";
                for (int k = 0; k < 5; ++k)
                    str += wood[j + k][i];
                if (str == "graph") {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;

}
