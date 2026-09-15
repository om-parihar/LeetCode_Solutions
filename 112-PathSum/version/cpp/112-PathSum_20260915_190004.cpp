// Last updated: 9/15/2026, 7:00:04 PM
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
14    bool dfs(TreeNode* root, int targetSum){
15        if(root==NULL) return false;
16        if(root->left==NULL && root->right==NULL){
17            return targetSum==root->val;
18        }
19        return dfs(root->left,targetSum-root->val) || dfs(root->right,targetSum-root->val);
20    }
21    bool hasPathSum(TreeNode* root, int targetSum) {
22        return dfs(root,targetSum);
23    }
24};