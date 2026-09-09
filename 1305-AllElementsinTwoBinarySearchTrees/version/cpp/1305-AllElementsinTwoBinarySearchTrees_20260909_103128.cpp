// Last updated: 9/9/2026, 10:31:28 AM
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
14    void inorder(TreeNode* root, unordered_map<int,int>& mp){
15        if(root==NULL) return;
16        inorder(root->left,mp);
17        mp[root->val]++;
18        inorder(root->right,mp);
19    }
20    vector<int> findMode(TreeNode* root) {
21        unordered_map<int,int> mp;
22        inorder(root,mp);
23        int mx=0;
24        for(auto it: mp){
25            mx=max(it.second,mx);
26        }
27        vector<int> ans;
28        for(auto it: mp){
29            if(it.second==mx){
30                ans.push_back(it.first);
31            }
32        }
33        return ans;
34    }
35};