// Last updated: 9/10/2026, 10:06:05 AM
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
14    pair<int,int> solve(TreeNode* root, int& cnt) {
15        if(root==NULL){
16            return {0,0};
17        }
18        auto left = solve(root->left,cnt);
19        auto right = solve(root->right,cnt);
20        int sum = root->val+left.first+right.first;
21        int nodes = 1 + left.second + right.second;
22        if(sum/nodes==root->val) cnt++;
23        return {sum,nodes};
24    }
25    int averageOfSubtree(TreeNode* root) {
26        int cnt=0;
27        solve(root,cnt);
28        return cnt;
29    }
30};