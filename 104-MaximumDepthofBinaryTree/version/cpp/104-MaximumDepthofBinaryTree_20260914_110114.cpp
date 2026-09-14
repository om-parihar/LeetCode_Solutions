// Last updated: 9/14/2026, 11:01:14 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    int dfs(TreeNode* root){
15        if(root && !root->left && !root->right) return 1;
16        if(root==NULL) return 1e9;
17        int l=dfs(root->left);
18        int r=dfs(root->right);
19        return 1+min(l,r);
20    }
21    int minDepth(TreeNode* root) {
22        if(!root) return 0;
23        int ans=dfs(root);
24        return ans;
25    }
26};