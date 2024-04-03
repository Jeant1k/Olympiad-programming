#include <iostream>
#include <vector>

using namespace std;

void no_more_no_less(vector<int> &a) {
    vector<int> lens;
    int count = 0, local_min = a[0];
    for (int i = 0; i < a.size(); ++i) {
        ++count;
        local_min = min(local_min, a[i + 1]);
        if (count >= local_min) {
            lens.push_back(count);
            count = 0;
            local_min = a[i + 1];
        }
    }
    if (count > 0) lens.push_back(count);
    cout << lens.size() << endl;
    for (int l : lens)
        cout << l << ' ';
    cout << endl;
}

int main() {

    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        no_more_no_less(a);
    }

    return 0;

}