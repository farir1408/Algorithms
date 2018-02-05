#include <iostream>
#include <stack>

template <class T>
class AVLtree {
public:
    explicit AVLtree() : root(nullptr) {}
    ~AVLtree() {delete root;}

private:
    struct AvlNode {
        T value;
        int height;
        AvlNode* left;
        AvlNode* right;

        explicit AvlNode(const T& Val) : value(Val), height(0), left(nullptr), right(nullptr) {}
    };
    void __height(const AvlNode* node);
    void __bfactor(const AvlNode* node);
    void __fixHeight(AvlNode* node);

    AvlNode* __rotateLeft(AvlNode* node) {
        AvlNode* p = node->right;
        node->right = p->left;
        p->left = node;

        __fixHeight(node);
        __fixHeight(p);

        return p;
    }

    AvlNode* __rotateRight(AvlNode* node) {

    }

};

void AVLtree::__height(const AvlNode* node) {
    return node == nullptr ? 0 : node->height;
}

void AVLtree::__bfactor(const AvlNode* node) {
    return __height(node->left) - __height(node->right);
}

void AVLtree::__fixHeight(AvlNode* node) {
    int t1 = __height(node->left);
    int t2 = __height(node->right);
    node->height = (t1 > t2 ? t1 : t2);
}



int main() {

}
