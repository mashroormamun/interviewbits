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
    bool isSymmetricEqual(TreeNode* a, TreeNode* b) {
        if(a==nullptr && b==nullptr) return true;
        if(a!=nullptr && b==nullptr) return false;
        if(a==nullptr && b!=nullptr) return false;
        if(a->val != b->val) return false;

        return isSymmetricEqual(a->left, b->right) && isSymmetricEqual(a->right, b->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return false;
        return isSymmetricEqual(root->left, root->right);
    }

};

// in order traversal will not work
// class Solution {
// public:
//     vector<int> inorder;

//     bool isSymmetric(TreeNode* root) {
//         inorderTraversal(root);

//         for(int i=0; i<inorder.size()/2; i++) {
//             if(inorder[i] != inorder[inorder.size()-1-i]) return false;
//         }

//         return true;
//     }

//     void inorderTraversal(TreeNode* root) {
//         if(root == nullptr) return;
        
//         inorderTraversal(root->left);
//         inorder.push_back(root->val);
//         inorderTraversal(root->right);
//     }
// };