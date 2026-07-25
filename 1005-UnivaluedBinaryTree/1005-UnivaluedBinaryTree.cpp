// Last updated: 7/25/2026, 10:58:11 PM
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
    void check(TreeNode* root, bool &flag, int data){
        if(root==NULL||flag==0) return;
        if(root->val!=data){
            flag=0;
            return;
        }
        check(root->left,flag,data);
        check(root->right,flag,data);
    }
    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return 1;
        bool flag=1;
        int data=root->val;
        check(root,flag,data);
        return flag;
    }
};