// Last updated: 7/25/2026, 11:01:42 PM
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
    int check(TreeNode* root, int &cnt){
        if(root==NULL) return 0;
        int l=max(0,check(root->left,cnt));
        int r=max(0,check(root->right,cnt));
        cnt=max(cnt,l+r+root->val);
        return root->val+max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int cnt=INT_MIN;
        check(root,cnt);
        return cnt;
    }
};