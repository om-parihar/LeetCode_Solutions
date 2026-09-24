// Last updated: 9/24/2026, 4:38:26 PM
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
14    void dfs(TreeNode* root, int &sum) {
15        if(root==NULL){
16            return;
17        }
18        dfs(root->left,sum);
19        sum=sum-root->val;
20        root->val=root->val+sum;
21        dfs(root->right,sum);
22    }
23    void ino(TreeNode* root, vector<int>& inorder) {
24        if(root==NULL){
25            return;
26        }
27        ino(root->left,inorder);
28        inorder.push_back(root->val);
29        ino(root->right,inorder);
30    }
31    TreeNode* convertBST(TreeNode* root) {
32        vector<int> inorder;
33        ino(root,inorder);
34        int n=inorder.size()-1;
35        int sum=0;
36        for(int i=0;i<inorder.size();i++) sum+=inorder[i];
37        dfs(root,sum);
38        return root;
39    }
40};