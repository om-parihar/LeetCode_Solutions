// Last updated: 10/23/2026, 12:19:15 PM
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
12class Solution1 {
13public:
14    vector<int> rightSideView(TreeNode* root) {
15        vector<int> ans;
16        if(root==NULL) return ans;
17        queue<TreeNode*>q;
18        q.push(root);
19        while(!q.empty()){
20            int size=q.size();
21            for(int i=0;i<size;i++){
22                TreeNode* curr=q.front();
23                q.pop();
24                if(i==size-1){
25                    ans.push_back(curr->val);
26                }
27                if(curr->left){
28                    q.push(curr->left);
29                }
30                if(curr->right){
31                    q.push(curr->right);
32                }
33            }
34        }
35        return ans;
36    }
37};
38
39class Solution{
40public:
41    void dfs(TreeNode* root,int level, vector<int>& ans){
42        if(root==NULL){
43            return;
44        }
45        if(level==ans.size()){
46            ans.push_back(root->val);
47        }
48        dfs(root->right,level+1,ans);
49        dfs(root->left,level+1,ans);
50    }
51
52    vector<int> rightSideView(TreeNode* root){
53        vector<int> ans;
54        if(root==NULL) return ans;
55        dfs(root,0,ans);
56        return ans;
57    }
58};