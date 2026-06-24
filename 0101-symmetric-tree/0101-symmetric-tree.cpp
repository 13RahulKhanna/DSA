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
    vector<int> a, b;
    bool mirror(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false;
        if(a -> val != b -> val) return false;
        
        return mirror(a -> left, b -> right) && mirror(a -> right, b -> left);

    }


    bool isSymmetric(TreeNode* root) {
        TreeNode* a = root -> left;
        TreeNode* b = root -> right;
        return mirror(a, b);

    }
};