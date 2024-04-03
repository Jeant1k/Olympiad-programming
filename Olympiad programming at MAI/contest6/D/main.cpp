#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
    struct Node {
        unordered_map<string, Node*> next;
        bool is_end;
        Node(bool flag) : is_end(flag) {}
    };

    Node* root;

public:
    Trie() : root(new Node(false)) {}

    void insert(const string& name) {
        // cout << "insert: ";
        istringstream iss(name);
        string part;
        vector<string> parts;
        while (getline(iss, part, '-')) {
            // cout << part << ' ';
            parts.push_back(part);
        }
        // cout << endl;
        Node* cur = root;
        for (int i = parts.size() - 1; i >= 0; --i) {
            if (cur->next.find(parts[i]) == cur->next.end()) {
                cur->next[parts[i]] = new Node(false);
            }
            cur = cur->next[parts[i]];
        }
        cur->is_end = true;
    }

    bool search(const string& name) {
        // cout << "search: ";
        istringstream iss(name);
        string part;
        vector<string> parts;
        while (getline(iss, part, '-')) {
            parts.push_back(part);
            // cout << part << ' ';
        }
        // cout << endl;
        Node* cur = root;
        for (int i = parts.size() - 1; i >= 0; --i) {
            if (cur->next.find(parts[i]) == cur->next.end()) {
                return true;
            } else {
                cur = cur->next[parts[i]];
            }
            if (cur->is_end) return false;
        }
        return true;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Trie trie;

    int n;
    cin >> n;
    string s;
    while (n--) {
        cin >> s;
        trie.insert(s);
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (trie.search(s)) cout << "Good" << endl;
        else cout << "Bad" << endl;
    }

    return 0;
}
