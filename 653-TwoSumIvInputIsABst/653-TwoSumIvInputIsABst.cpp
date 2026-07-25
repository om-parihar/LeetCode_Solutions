// Last updated: 7/25/2026, 10:58:57 PM
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
    void check(TreeNode* root, vector<int>& ans){
        if(root==NULL){
            return;
        }
        check(root->left,ans);
        ans.push_back(root->val);
        check(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        check(root,ans);
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            int sum=ans[i]+ans[j];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
    }
};