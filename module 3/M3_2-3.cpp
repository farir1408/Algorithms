#include <iostream>

class Tree {
public:
    explicit Tree() : root(nullptr) {}
    ~Tree() {delete root;}

    void Add(int);
    void DFS();
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;

        explicit TreeNode(int Value) : data(Value), left(0), right(0) {}
        ~TreeNode() {delete left; delete right;}
    };
    TreeNode* root;
    void __DFS(TreeNode* node);
    void __Visit(TreeNode* node);

};

void Tree::Add(int value) {
    TreeNode* Node = new TreeNode(value);

    if (root == nullptr) {
        root = Node;
        return;
    }

    TreeNode* nextNode = root;

    while (true) {
        if (nextNode->data > value) {
            if (nextNode->left != nullptr) {
                nextNode = nextNode->left;
            } else {
                nextNode->left = Node;
                return;
            }
        } else {
            if (nextNode->right != nullptr) {
                nextNode = nextNode->right;
            } else {
                nextNode->right = Node;
                return;
            }
        }
    }
}

void Tree::__Visit(TreeNode* node) {
    std::cout << node->data << " ";
}

void Tree::DFS() {
    __DFS(root);
}

void Tree::__DFS(TreeNode *node) {

    if (node == nullptr)
        return;

    __DFS(node->left);
    __DFS(node->right);
    __Visit(node);
}

int main() {
    size_t N = 0;
    int value = 0;

    std::cin >> N;

    if (N == 0)
        return 0;

    Tree tree;

    for (size_t i = 0; i < N; i++) {
        std::cin >> value;
        tree.Add(value);
    }

    tree.DFS();

    return 0;
}
