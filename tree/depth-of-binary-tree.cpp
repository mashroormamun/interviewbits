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
    int maxDepth(TreeNode* root, int depth) {
        if(root==nullptr) return depth;

        int l_d = maxDepth(root->left, depth+1);
        int r_d = maxDepth(root->right, depth+1);

        int max = l_d > r_d ? l_d : r_d;

        return max;
    }

    int maxDepth(TreeNode* root) {
        return maxDepth(root, 0);
    }
};

