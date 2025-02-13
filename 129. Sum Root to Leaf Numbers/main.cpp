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
    int sum = 0;

    void inorder(TreeNode* root, int pathSum) {
        if(root == nullptr) return;

        if(root->left != nullptr) {
            inorder(root->left, pathSum * 10 + root->val);
        }

        if(root->left == nullptr && root->right == nullptr) sum+=pathSum * 10 + root->val;

        if(root->right != nullptr) {
            inorder(root->right, pathSum * 10 + root->val);
        }
    }

    int sumNumbers(TreeNode* root) {
        inorder(root, 0);
        return sum;
    }
};
