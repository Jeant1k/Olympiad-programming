#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> result(n - 1, 0);

    vector<int> amountParts(k, 1);

    vector<vector<bool>> divecesParts(n, vector<bool>(k, 0));
    divecesParts[0] = vector<bool>(k, 1);
    
    vector<vector<bool>> partsDevices(k, vector<bool>(n));
    for (int i = 0; i < k; ++i) partsDevices[i][0] = 1;
    

    while (*min_element(amountParts.begin(), amountParts.end()) < k) {
        for ()
    }

    return 0;

}