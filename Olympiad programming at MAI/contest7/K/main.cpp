#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
    BinaryTree(int n) { root = buildTree(1, n); }

    void print() { printInOrder(root); cout << endl; }

    void remove(int n) {
        root = remove(root, n, true);
        // this->print();
    }

    void printResult() { printRes(); }

private:
    struct Node {
        int data;
        int leftCount;
        int rightCount;
        Node* left;
        Node* right;

        Node(int data)
            : data(data)
            , leftCount(0)
            , rightCount(0)
            , left(nullptr)
            , right(nullptr)
        {}
    };

    Node* root;
    vector<int> result;

    Node* buildTree(int start, int end) {
        if (start > end) return nullptr;

        int mid = (start + end) / 2;
        Node* node = new Node(mid);

        node->left = buildTree(start, mid - 1);
        if (node->left) node->leftCount = mid - start;

        node->right = buildTree(mid + 1, end);
        if (node->right) node->rightCount = end - mid;

        return node;
    }

    Node* remove(Node* node, int n, bool flag) {
        if (node == nullptr) return nullptr;

        if (node->leftCount + 1 < n) {
            node->rightCount--;
            if (flag) node->right = remove(node->right, n - node->leftCount - 1, true);
            else node->right = remove(node->right, n - node->leftCount - 1, false);
        } else if (node->leftCount + 1 > n) {
            node->leftCount--;
            if (flag) node->left = remove(node->left, n, true);
            else node->left = remove(node->left, n, false);
        } else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                if (flag) result.push_back(node->data);
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                if (flag) result.push_back(node->data);
                delete node;
                return temp;
            } else {
                result.push_back(node->data);
                Node* temp = node->left;
                while (temp->right != nullptr) temp = temp->right;
                node->data = temp->data;
                node->leftCount--;
                node->left = remove(node->left, node->leftCount + 1, false);
            }
        }

        return node;
    }


    void printInOrder(Node* node) {
        if (node == nullptr) return;
        printInOrder(node->left);
        cout << "(" << node->data << ", " << node->leftCount << ", " << node->rightCount << ") ";
        printInOrder(node->right);
    }

    void printRes() {
        for (int i = 0; i < result.size(); i += 2) cout << result[i] << ' ';
        cout << endl;
        for (int i = 1; i < result.size(); i += 2) cout << result[i] << ' ';
        cout << endl;
    }
};


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    BinaryTree bt(n);

    // bt.print();

    vector<int> choices(n);
    for (int i = 0; i < n; i += 2) cin >> choices[i];
    for (int i = 1; i < n; i += 2) cin >> choices[i];

    // for (int c : choices) cout << c << ' ';
    // cout << endl;

    for (int choice : choices) bt.remove(choice);

    bt.printResult();

    return 0;

}
