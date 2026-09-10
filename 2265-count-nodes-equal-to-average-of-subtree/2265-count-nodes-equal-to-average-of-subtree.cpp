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

    int fn(TreeNode* root, int& cnt, int& ans){

        int sum = root->val;

        cnt = 1;

        if(root->left){

            int leftCnt = 0;

            sum += fn(root->left, leftCnt, ans);

            cnt += leftCnt;
        }

        if(root->right){

            int rightCnt = 0;

            sum += fn(root->right, rightCnt, ans);

            cnt += rightCnt;
        }

        cout << sum << " " << cnt << " " << root->val << endl;

        if(sum / cnt == root->val){
            ans++;
        }

        return sum;
    }

    int averageOfSubtree(TreeNode* root) {

        int ans = 0;

        int cnt = 0;

        fn(root, cnt, ans);

        return ans;
    }
};