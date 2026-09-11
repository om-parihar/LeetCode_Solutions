// Last updated: 9/11/2026, 7:02:35 PM
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
14    int maxLevelSum(TreeNode* root) {
15        if(root==NULL) return 0;
16        int c=1;
17        queue<TreeNode*> q;
18        q.push(root);
19        int mx=root->val;
20        int idx=1;
21        while(!q.empty()){
22            int sz=q.size();
23            int sum=0;
24            for(int i=0;i<sz;i++){
25                TreeNode* x=q.front();
26                q.pop();
27                sum+=x->val;
28                if(x->left) q.push(x->left);
29                if(x->right) q.push(x->right);
30            }
31            if(sum>mx){
32                idx=c;
33                mx=max(sum,mx);
34            }
35            c++;
36        }
37        return idx;
38    }
39};