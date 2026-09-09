// Last updated: 9/9/2026, 6:28:19 PM
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
14    int maxl=-1;
15    void solve(TreeNode* r, int lev, int& ans, int &maxl){
16        if(r==NULL) return;
17        if(lev>maxl){
18            maxl=lev;
19            ans=r->val;
20        }
21        else if(lev==maxl){
22            ans+=r->val;
23        }
24        solve(r->left,lev+1,ans,maxl);
25        solve(r->right,lev+1,ans,maxl);
26    } 
27    int deepestLeavesSum(TreeNode* root) {
28        int ans=0;
29        int maxl=-1;
30        solve(root,0,ans,maxl);
31        return ans;
32    }
33};
34
35
36class Solution2 {
37public:
38    int deepestLeavesSum(TreeNode* root) {
39        int ans=0;
40        queue<pair<TreeNode*,int>> q;
41        q.push({root,root->val});
42        while(!q.empty()){
43            int size=q.size();
44            ans=0;
45            for(int i=0;i<size;i++){
46                auto x=q.front();
47                ans+=x.second;
48                q.pop();
49                if(x.first->left){
50                    q.push({x.first->left,x.first->left->val});
51                } 
52                if(x.first->right){
53                    q.push({x.first->right,x.first->right->val});
54                }
55            }
56        }
57        return ans;
58    }
59};
60
61class Solution1 {
62public:
63    void preorder(int level,TreeNode* r, priority_queue<pair<int,int>>& pq){
64        if(r==NULL) return;
65        pq.push({level,r->val});
66        preorder(level+1,r->left,pq);
67        preorder(level+1,r->right,pq);
68    }
69    int deepestLeavesSum(TreeNode* root) {
70        priority_queue<pair<int,int>> pq;
71        preorder(0,root,pq);
72        auto a=pq.top();
73        int lev=a.first;
74        int val=a.second;
75        int ans=0;
76        while(!pq.empty()){
77            auto x=pq.top();
78            pq.pop();
79            if(x.first==lev){
80                ans+=x.second;
81            }
82            else{
83                break;
84            }
85        }
86        return ans;
87    }
88};