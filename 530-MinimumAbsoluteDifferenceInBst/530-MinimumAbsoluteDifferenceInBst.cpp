// Last updated: 7/25/2026, 10:59:17 PM
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
    TreeNode* prev=NULL;
    void check(TreeNode* root, int &ans){
        if(root==NULL){
            return;
        }
        check(root->left,ans);
        if(prev!=NULL){
            ans=min(ans,root->val-prev->val);
        }
        prev=root;
        check(root->right,ans);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int ans=INT_MAX;
        check(root,ans);
        return ans;
    }
};