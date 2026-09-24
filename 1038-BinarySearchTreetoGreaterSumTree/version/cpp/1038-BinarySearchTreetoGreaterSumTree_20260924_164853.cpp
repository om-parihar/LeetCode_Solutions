// Last updated: 9/24/2026, 4:48:53 PM
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
14    void dfs(TreeNode* root, int &sum){
15        if(root==NULL) return;
16        dfs(root->left,sum);
17        sum=sum-root->val;
18        root->val=root->val+sum;
19        dfs(root->right,sum);
20    }
21    void ino(TreeNode* root, vector<int>& valu) {
22        if(root==NULL){
23            return;
24        }
25        ino(root->left,valu);
26        valu.push_back(root->val);
27        ino(root->right,valu);
28    }
29    TreeNode* bstToGst(TreeNode* root) {
30        vector<int> valu;
31        ino(root,valu);
32        int sum=0;
33        for(int i=0;i<valu.size();i++) sum+=valu[i];
34        dfs(root,sum);
35        return root;
36    }
37};