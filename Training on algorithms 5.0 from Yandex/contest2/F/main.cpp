#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> numbers1(n);
    vector<int> numbers2(n);
    int number;
    for (int i = 0; i < n; ++i)
        cin >> numbers1[i];

    numbers2 = numbers1;
    numbers2.push_back(numbers1[0]);
    reverse(numbers2.begin(), numbers2.end());
    numbers2.pop_back();

    int a, b;
    double k;
    cin >> a >> b >> k;

    double cheat_k = k + 0.000000000001;

    int begin = int(a / cheat_k) % n, end = int(b / cheat_k) % n;
    if ((b - a) / k >= n) begin = 0, end = n - 1;

    // cout << "begin = " << begin << " end = " << end << endl;

    int max_number = 0;
    if (begin > end) {
        for (int i = begin; i < n; ++i) max_number = max(numbers1[i], max_number);
        for (int i = 0; i <= end; ++i) max_number = max(numbers1[i], max_number);
        for (int i = begin; i < n; ++i) max_number = max(numbers2[i], max_number);
        for (int i = 0; i <= end; ++i) max_number = max(numbers2[i], max_number);
    } else {
        for (int i = begin; i <= end; ++i) max_number = max(numbers1[i], max_number);
        for (int i = begin; i <= end; ++i) max_number = max(numbers2[i], max_number);
    }
          
    cout << max_number << endl;

    return 0;

}
