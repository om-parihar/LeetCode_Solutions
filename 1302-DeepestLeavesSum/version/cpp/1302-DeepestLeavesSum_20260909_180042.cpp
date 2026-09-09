// Last updated: 9/9/2026, 6:00:42 PM
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
14    void preorder(int level,TreeNode* r, priority_queue<pair<int,int>>& pq){
15        if(r==NULL) return;
16        pq.push({level,r->val});
17        preorder(level+1,r->left,pq);
18        preorder(level+1,r->right,pq);
19    }
20    int deepestLeavesSum(TreeNode* root) {
21        priority_queue<pair<int,int>> pq;
22        preorder(0,root,pq);
23        auto a=pq.top();
24        int lev=a.first;
25        int val=a.second;
26        int ans=0;
27        while(!pq.empty()){
28            auto x=pq.top();
29            pq.pop();
30            if(x.first==lev){
31                ans+=x.second;
32            }
33            else{
34                break;
35            }
36        }
37        return ans;
38    }
39};