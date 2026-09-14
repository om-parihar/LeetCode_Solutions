// Last updated: 9/14/2026, 10:10:14 AM
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
14    int dfs(TreeNode* root,int &ans){
15        if(root==NULL) return 0;
16        int left=dfs(root->left,ans);
17        int right=dfs(root->right,ans);
18        ans+=abs(left)+abs(right);
19        return root->val+left+right-1;
20    }
21    int distributeCoins(TreeNode* root) {
22        int ans=0;
23        dfs(root,ans);
24        return ans;
25    }
26};