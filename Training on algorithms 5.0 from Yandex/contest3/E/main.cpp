#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

void find_intersection(unordered_set<int>& a, unordered_set<int>& b, unordered_set<int>& own) {

    for (int num : a)
        if (b.find(num) != b.end()) own.insert(num);

}

void write_to_set(unordered_set<int>& a) {

    int n, num;
    cin >> n;
    while (n--) {
        cin >> num;
        a.insert(num);
    }

}

int main() {

    unordered_set<int> a, b, c;
    write_to_set(a);
    write_to_set(b);
    write_to_set(c);
    
    unordered_set<int> own;
    find_intersection(a, b, own);
    find_intersection(b, c, own);
    find_intersection(c, a, own);

    vector<int> result;
    for (int num : own) result.push_back(num);

    sort(result.begin(), result.end());

    for (int num : result) cout << num << ' ';
    cout << endl;
    
    return 0;

}