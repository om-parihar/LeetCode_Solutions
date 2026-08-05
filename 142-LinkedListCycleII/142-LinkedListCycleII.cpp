// Last updated: 8/5/2026, 12:51:36 PM
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
14    void trav(TreeNode* root, int &ans, int sum){
15        if(root==NULL){
16            return;
17        }
18        sum=sum*10+root->val;
19        if(!root->left && !root->right){
20            ans+=sum;
21            return;
22        }
23        trav(root->left,ans,sum);
24        trav(root->right,ans,sum);
25    }
26    int sumNumbers(TreeNode* root) {
27        int ans=0;
28        int sum=0;
29        trav(root,ans,sum);
30        return ans;
31    }
32};