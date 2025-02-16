#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

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
    unordered_map<string, pair<int, TreeNode*>> m;

    string preorderPath(TreeNode* n, string &order) {
        if(n==nullptr) {
            order += "n";
            return order;
        }

        order += to_string(n->val)+"|";

        preorderPath(n->left, order);
        preorderPath(n->right, order);

        return order;
    }

    void preorderTraversal(TreeNode* n) {
        if(n==nullptr) {
            return;
        }

        string o="";
        string key = preorderPath(n, o);

        cout << key << endl;

        m[key] = pair<int, TreeNode*>(m[key].first+1, n);

        // cout << key << " : " << m[key].first << " " << m[key].second->val << endl;

        preorderTraversal(n->left);
        preorderTraversal(n->right);
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preorderTraversal(root);

        vector<TreeNode*> v;
        for(auto it=m.begin();it!=m.end();it++) {
            // cout << it->first << " " << it->second.first << endl;

            if(it->second.first > 1) {
                v.push_back(it->second.second);
            }
        }

        return v;
    }
};


int main() {
    TreeNode *ptr;

    ptr = new TreeNode(2);

    ptr->left = new TreeNode(1);
    ptr->right = new TreeNode(11);

    ptr->left->left = new TreeNode(11);
    ptr->right->left = new TreeNode(1);
    // ptr->right->right = new TreeNode(4);

    // ptr->right->left->left = new TreeNode(4);

    Solution s;
    auto v = s.findDuplicateSubtrees(ptr);

    for(int i=0;i<v.size();i++) {
        cout << v[i]->val << endl;
    }

    return 0;
}
