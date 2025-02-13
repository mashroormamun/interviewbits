#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        queue<TreeNode*> BFS;
        BFS.push(root);

        while(!BFS.empty()) {
            TreeNode* n = BFS.front();
            if(n->left != nullptr) BFS.push(n->left);
            if(n->right != nullptr) BFS.push(n->right);
            BFS.pop();

            if(n->left != nullptr && n->right != nullptr) {
                TreeNode* temp = n->left;
                n->left = n->right;
                n->right = temp;
            } else if (n->left == nullptr && n->right != nullptr){
                n->left = n->right;
                n->right = nullptr;
            } else if (n->left != nullptr && n->right == nullptr){
                n->right = n->left;
                n->left = nullptr;
            }

        }

        return root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution s;
    auto a = s.invertTree(root);

    cout << a->val << endl;
    cout << a->left->val << endl;
    cout << a->right->val << endl;

    return 0;
}