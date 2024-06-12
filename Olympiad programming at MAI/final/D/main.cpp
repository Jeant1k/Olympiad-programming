#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Tree {
private:
    class Node {
    public:
        int num;
        int value;
        int numEdge;
        vector<Node*> children;

        Node(int num) : num(num) {}
    };

    void print(Node* node, int depth = 0) {

        string indent(depth, '\t');
        cout << indent << "(" << node->num << ", " << node->value << ", " << node->numEdge << ")" << endl;

        for (Node* child : node->children)
            print(child, depth + 1);

    }

    long long findDivEdges(Node* node) {

        if (!root) return 1;

        long long prod = node->value;
        for (Node* child : node->children) {
            prod *= findDivEdges(child);
        }

        if (prod != 0) {
            long long prodOtherTree = production / prod;
            if (max(prodOtherTree, prod) % min(prodOtherTree, prod) == 0)
                divEdges.push_back(node->numEdge);
        }

        return prod;

    }

    Node* root;
    unordered_map<int, Node*> nodes;
    long long production;

    vector<int> divEdges;

public:
    Tree(int rootNum) : root(new Node(rootNum)), production(1) {
        nodes[rootNum] = root;
        nodes[rootNum]->numEdge = INT_MIN;
    }

    void print() {
        cout << "production = " << production << endl;
        print(root);
    }

    void addEdges(const vector<vector<int>>& edges, const vector<int>& values) {

        for (auto& edge : edges) {
            if (nodes.find(edge[0]) == nodes.end()) nodes[edge[0]] = new Node(edge[0]);
            if (nodes.find(edge[1]) == nodes.end()) nodes[edge[1]] = new Node(edge[1]);
        }

        for (auto& edge : edges) {
            nodes[edge[0]]->children.push_back(nodes[edge[1]]);
            nodes[edge[1]]->numEdge = edge[2];
        }

        for (int i = 0; i < values.size(); ++i) {
            nodes[i]->value = values[i];
            production *= values[i];
        }

    }

    vector<int> findDivEdges() {
        findDivEdges(root);
        return divEdges;
    }

};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> values(n);
    for (int i = 0; i < n; ++i) cin >> values[i];

    vector<bool> findRoot(n, false);
    vector<vector<int>> edges(n - 1, vector<int>(3));
    for (int i = 0; i < n - 1; ++i) {
        cin >> edges[i][0] >> edges[i][1];
        --edges[i][0];
        --edges[i][1];
        edges[i][2] = i;
        findRoot[edges[i][1]] = true;
    }

    int numRoot = -1;
    for (int i = 0; i < n; ++i)
        if (!findRoot[i]) numRoot = i;

    Tree tree(numRoot);

    tree.addEdges(edges, values);

    tree.print();

    auto result = tree.findDivEdges();
    sort(result.begin(), result.end());

    cout << result.size() - 1 << endl;
    for (int i = 1; i < result.size(); ++i) cout << result[i] + 1 << ' ';
    cout << endl;

    return 0;

}
