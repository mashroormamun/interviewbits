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
    long long int prev = (long long int)INT_MIN-10;

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;

        if(!isValidBST(root->left)) return false;

        // if(root->left != nullptr) {
        //     if(root->val <= root->left->val) return false;
        // }

        // if(root->right != nullptr) {
        //     if(root->val >= root->right->val) return false;
        // }

        if(root->val <= prev) return false;
        prev = root->val;

        if(!isValidBST(root->right)) return false;

        return true;
    }
};
