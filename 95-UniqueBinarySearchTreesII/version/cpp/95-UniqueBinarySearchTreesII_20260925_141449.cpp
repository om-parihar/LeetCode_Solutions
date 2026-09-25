// Last updated: 9/25/2026, 2:14:49 PM
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
14    vector<TreeNode*> build(int start, int end) {
15        vector<TreeNode*> ans;
16        if(start>end){
17            ans.push_back(nullptr);
18            return ans;
19        }
20        for(int i=start;i<=end;i++){
21            vector<TreeNode*> left=build(start,i-1);
22            vector<TreeNode*> right=build(i+1,end);
23            for(TreeNode* l: left){
24                for(TreeNode* r: right){
25                    TreeNode* root= new TreeNode(i);
26                    root->left=l;
27                    root->right=r;
28                    ans.push_back(root);
29                }
30            }
31        }
32        return ans;
33    }
34    vector<TreeNode*> generateTrees(int n) {
35        if(n==0) return {};
36        return build(1,n);
37    }
38};