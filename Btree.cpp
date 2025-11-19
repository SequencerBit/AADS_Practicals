#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

const int T = 3; 

class BTreeNode {
public:
    vector<int> keys;          
    vector<BTreeNode*> child;  
    bool leaf;                 
    BTreeNode(bool isLeaf) : leaf(isLeaf) {}
};

class BTree {
public:
    BTreeNode* root;

    BTree() : root(new BTreeNode(true)) {}
    void insert(int k) {
        root->keys.push_back(k);
        sort(root->keys.begin(), root->keys.end());
    }

    void printRoot() const {
        cout << "Keys in root: ";
        for (int k : root->keys) cout << k << " ";
        cout << endl;
    }
};

int main() {
    BTree t;
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(6);
    t.insert(12);

    t.printRoot();
    return 0;
}
