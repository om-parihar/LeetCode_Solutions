// Last updated: 9/24/2026, 7:06:26 PM
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
14    void dfs(TreeNode* root, vector<int>& ino) {
15        if(root==NULL) return;
16        dfs(root->left,ino);
17        ino.push_back(root->val);
18        dfs(root->right,ino);
19    }
20    TreeNode* increasingBST(TreeNode* root) {
21        vector<int> ino;
22        dfs(root,ino);
23        TreeNode* ans=new TreeNode(0);
24        TreeNode* curr=ans;
25        for(int i=0;i<ino.size();i++){
26            curr->right=new TreeNode(ino[i]);
27            curr=curr->right;
28        }
29        return ans->right;
30    }
31};