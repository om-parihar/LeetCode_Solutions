// Last updated: 7/25/2026, 11:02:02 PM
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
    void preorder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            ans.push_back(100);
            return;
        }
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a;
        vector<int> b;
        preorder(p,a);
        preorder(q,b);
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};