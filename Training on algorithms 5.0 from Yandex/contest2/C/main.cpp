#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;

    int sum = 0, max_len = 0;
    while (n--) {
        int len;
        cin >> len;
        sum += len;
        max_len = max(max_len, len);
    }

    int result = max_len - sum + max_len;
    if (result <= 0) result = sum;

    cout << result << endl;

    return 0;

}