// Last updated: 9/15/2026, 7:13:04 PM
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
14    void dfs(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int>& temp){
15        if(root==NULL) return;
16        if(root->left==NULL && root->right==NULL){
17            if(targetSum-root->val==0){
18                temp.push_back(root->val);
19                ans.push_back(temp);
20                temp.pop_back();
21                return;
22            }
23            return;
24        }
25        temp.push_back(root->val); 
26        dfs(root->left,targetSum-root->val,ans,temp);
27        dfs(root->right,targetSum-root->val,ans,temp);
28        temp.pop_back();
29    }
30    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
31        vector<vector<int>> ans;
32        vector<int> temp;
33        dfs(root,targetSum,ans,temp);
34        return ans;
35    }
36};