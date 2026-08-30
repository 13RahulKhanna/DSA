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
    int fn(TreeNode* root){
        if(!root) return INT_MAX / 2;
        if(!root -> left && !root -> right) return 1;
        return 1 + min(fn(root -> left), fn(root -> right)); 
    }
    int minDepth(TreeNode* root) {
        int ans = fn(root);
        return ans >= INT_MAX / 2 ? 0 : ans;
    }
};