/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createTree(TreeNode* orig, TreeNode* newT) {
        if(orig == nullptr) return;

        if(orig->left != nullptr) {
            newT->right = new TreeNode(orig->left->val);
            createTree(orig->left, newT->right);
        }

        if(orig->right != nullptr) {
            newT->left = new TreeNode(orig->right->val);
            createTree(orig->right, newT->left);
        }
    }

    TreeNode* invertTree(TreeNode* root) {
        TreeNode* result = nullptr;

        if(root != nullptr) {
            result = new TreeNode(root->val);
            createTree(root, result);
        }

        return result;
    }
};
