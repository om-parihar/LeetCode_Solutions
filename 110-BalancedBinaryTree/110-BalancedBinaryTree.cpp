// Last updated: 7/25/2026, 11:01:50 PM
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
    int check(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return 1+(max(check(root->left),check(root->right)));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh=check(root->left);
        int rh=check(root->right);
        if(abs(lh-rh)>1) return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
};