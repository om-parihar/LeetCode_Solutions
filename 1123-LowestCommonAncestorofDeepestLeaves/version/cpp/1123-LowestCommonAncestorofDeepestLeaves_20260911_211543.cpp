// Last updated: 9/11/2026, 9:15:43 PM
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
14    pair<TreeNode*, int> solve(TreeNode* root) {
15        if(root == NULL)
16            return {NULL, 0};
17
18        auto left = solve(root->left);
19        auto right = solve(root->right);
20
21        if(left.second == right.second) {
22            return {root, left.second + 1};
23        }
24
25        if(left.second > right.second) {
26            return {left.first, left.second + 1};
27        }
28
29        return {right.first, right.second + 1};
30    }
31
32    TreeNode* lcaDeepestLeaves(TreeNode* root) {
33        return solve(root).first;
34    }
35};
36
37
38class Solution1 {
39public:
40    TreeNode* lcaDeepestLeaves(TreeNode* root) {
41        if(root==NULL) return NULL;
42        queue<pair<TreeNode*,TreeNode*>> q;
43        TreeNode* ans=root;
44        q.push({NULL,root});
45        while(!q.empty()){
46            int sz=q.size();
47            for(int i=0;i<sz;i++){
48                pair<TreeNode*,TreeNode*> node=q.front();
49                if(q.front().second->left && q.front().second->right) ans=q.front().second;
50                q.pop();
51                if(node.second->left) q.push({node.second,node.second->left});
52                if(node.second->right) q.push({node.second,node.second->right});
53            }
54        }
55        return ans;
56    }
57};