// Last updated: 10/25/2026, 9:46:27 PM
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
14    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
15        if(nums.empty()) return NULL;
16        int maxi=max_element(nums.begin(),nums.end())-nums.begin();
17        TreeNode* root=new TreeNode(nums[maxi]);
18        vector<int> left(nums.begin(),nums.begin()+maxi);
19        vector<int> right(nums.begin()+maxi+1,nums.end());
20        root->left=constructMaximumBinaryTree(left);
21        root->right=constructMaximumBinaryTree(right);
22        return root;
23    }
24};