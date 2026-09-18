// Last updated: 9/18/2026, 4:39:32 PM
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
14    TreeNode* trimBST(TreeNode* root, int low, int high) {
15        if(!root){
16            return NULL;
17        }
18        if(root->val<low){
19            return trimBST(root->right,low,high);
20        }
21        if(root->val>high){
22            return trimBST(root->left,low,high);
23        }
24        root->left=trimBST(root->left,low,high);
25        root->right=trimBST(root->right,low,high);
26        return root;
27    }
28};