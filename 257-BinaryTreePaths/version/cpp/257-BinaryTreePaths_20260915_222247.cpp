// Last updated: 9/15/2026, 10:22:47 PM
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
14    void dfs(TreeNode* root, stack<int> st, vector<string>& ans){
15        if(root==NULL){
16            return;
17        }
18        if(root->left==NULL && root->right==NULL){
19            st.push(root->val);
20            string temp;
21            vector<int> t;
22            while(!st.empty()){
23                t.push_back(st.top());
24                st.pop();
25            }
26            for(int i=t.size()-1;i>=0;i--){
27                temp+=to_string(t[i]);
28                if(i==0) continue;
29                temp+="->";
30            }
31            ans.push_back(temp);
32            return;
33        }
34        st.push(root->val);
35        dfs(root->left,st,ans);
36        dfs(root->right,st,ans);
37    }
38    vector<string> binaryTreePaths(TreeNode* root) {
39        stack<int> st;
40        vector<string> ans;
41        if(root==NULL) return ans;
42        dfs(root,st,ans);
43        return ans;
44    }
45};