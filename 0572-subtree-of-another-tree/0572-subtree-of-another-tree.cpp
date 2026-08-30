class Solution {
public:
    bool same(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;

        return p->val == q->val &&
               same(p->left, q->left) &&
               same(p->right, q->right);
    }

    bool fn(TreeNode* p, TreeNode* q) {
        if(!p) return false;

        if(same(p, q))
            return true;

        return fn(p->left, q) || fn(p->right, q);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return fn(root, subRoot);
    }
};