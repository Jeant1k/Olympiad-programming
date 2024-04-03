#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    string line;
    getline(cin, line);
    istringstream iss(line);

    string word;
    vector<string> words;
    while (iss >> word) words.push_back(word);

    sort(words.begin(), words.end());

    unordered_set<string> dict;
    for (string& word : words) {
        string prefix = "";
        for (char c : word) {
            prefix += c;
            if (dict.find(prefix) != dict.end()) break;
        }
        if (word == prefix) dict.insert(word);
    }

    getline(cin, line);
    iss.clear();
    iss.str(line);
    while (iss >> word) {
        string prefix = "";
        bool flag = false;
        for (char c : word) {
            prefix += c;
            if (dict.find(prefix) != dict.end()) {
                cout << prefix << ' ';
                flag = true;
                break;
            }
        }
        if (!flag) cout << word << ' ';
    }

    cout << endl;
    
    return 0;

}