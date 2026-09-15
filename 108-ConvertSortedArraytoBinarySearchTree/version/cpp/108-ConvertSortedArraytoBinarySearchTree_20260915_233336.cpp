// Last updated: 9/15/2026, 11:33:36 PM
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
14    TreeNode* solve(vector<int>& nums,int left, int right) {
15        if(left>right){
16            return NULL;
17        }
18        int mid = (left+right)/2;
19        TreeNode* root = new TreeNode(nums[mid]);
20        root->left=solve(nums,left,mid-1);
21        root->right=solve(nums,mid+1,right);
22        return root;
23    }
24    TreeNode* sortedArrayToBST(vector<int>& nums) {
25        return solve(nums,0,nums.size()-1);
26    }
27};