#include <bits/stdc++.h>

using namespace std;

bitset<30> getMask(int n) {
    string tmp = bitset<31>(n).to_string();
    tmp.pop_back();
    reverse(tmp.begin(), tmp.end());
    bitset<30> mask(tmp);
    return mask;
}

int main() {

    int q;
    cin >> q;

    vector<int> points(q);
    for (int i = 0; i < q; ++i)
        cin >> points[i];
    
    bitset<30> position(0);
    for (int i = q - 1; i >= 0; --i) {
        // cout << "n = " << points[i] << '\t';
        bitset<30> mask = getMask(points[i]);
        // cout << " mask = " << mask << '\t';
        position = position ^ mask;
        // cout << " position = " << position << endl;
    }

    cout << position.count() << endl;

    return 0;
    
}
