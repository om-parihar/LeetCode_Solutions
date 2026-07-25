// Last updated: 7/25/2026, 11:00:35 PM
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
    void preorder(TreeNode* root,priority_queue<int,vector<int>, greater<int>> &q){
        if(root==NULL){
            return;
        }
        q.push(root->val);
        preorder(root->left,q);
        preorder(root->right,q);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>, greater<int>> q;
        preorder(root,q);
        int ans=0;
        while(k){
            ans=q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};