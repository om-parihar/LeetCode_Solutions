// Last updated: 9/15/2026, 10:07:57 PM
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
14    int dfs(TreeNode* root,int &cnt){
15        if(root==NULL) return 0;
16        int left = dfs(root->left,cnt);
17        int right = dfs(root->right,cnt);
18        if(root->val>=max(left,right)){
19            cnt++;
20            return root->val;
21        }
22        return max(left,right);
23    }
24    int countDominantNodes(TreeNode* root) {
25        if(root==NULL) return 0;
26        int cnt=0;
27        dfs(root,cnt);
28        return cnt;
29    }
30};