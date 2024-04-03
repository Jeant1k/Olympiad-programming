#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    stack<bool> st;
    vector<char> result(n - 1, '?');

    int a;
    bool flag;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        flag = a % 2 == 0 ? true : false;
        if (!st.empty() && (st.top() && !flag || !st.top() && flag)) {
            st.pop();
            st.push(false);
            result[i - 1] = '+';
        } else if (!st.empty() && (!st.top() && !flag)) {
            result[i - 1] = 'x';
        } else {
            st.push(flag);
        }
    }

    for (char r : result) {
        if (r == '?') {
            cout << '+';
            continue;
        }
        cout << r;
    }
    cout << endl;

    return 0;
}
