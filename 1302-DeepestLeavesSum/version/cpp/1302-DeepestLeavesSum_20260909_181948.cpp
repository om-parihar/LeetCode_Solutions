// Last updated: 9/9/2026, 6:19:48 PM
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
14    int deepestLeavesSum(TreeNode* root) {
15        int ans=0;
16        queue<pair<TreeNode*,int>> q;
17        q.push({root,root->val});
18        while(!q.empty()){
19            int size=q.size();
20            ans=0;
21            for(int i=0;i<size;i++){
22                auto x=q.front();
23                ans+=x.second;
24                q.pop();
25                if(x.first->left){
26                    q.push({x.first->left,x.first->left->val});
27                } 
28                if(x.first->right){
29                    q.push({x.first->right,x.first->right->val});
30                }
31            }
32        }
33        return ans;
34    }
35};
36
37class Solution1 {
38public:
39    void preorder(int level,TreeNode* r, priority_queue<pair<int,int>>& pq){
40        if(r==NULL) return;
41        pq.push({level,r->val});
42        preorder(level+1,r->left,pq);
43        preorder(level+1,r->right,pq);
44    }
45    int deepestLeavesSum(TreeNode* root) {
46        priority_queue<pair<int,int>> pq;
47        preorder(0,root,pq);
48        auto a=pq.top();
49        int lev=a.first;
50        int val=a.second;
51        int ans=0;
52        while(!pq.empty()){
53            auto x=pq.top();
54            pq.pop();
55            if(x.first==lev){
56                ans+=x.second;
57            }
58            else{
59                break;
60            }
61        }
62        return ans;
63    }
64};