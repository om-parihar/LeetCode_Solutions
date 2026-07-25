// Last updated: 7/25/2026, 10:59:45 PM
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
    int check(TreeNode* root, int &ans){
        if(root==NULL){
            return 0;
        }
        if(root->left&& !root->left->left && !root->left->right){
            ans+=root->left->val;
        }
        check(root->left,ans);
        check(root->right,ans);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        check(root,ans);
        return ans;
    }
};