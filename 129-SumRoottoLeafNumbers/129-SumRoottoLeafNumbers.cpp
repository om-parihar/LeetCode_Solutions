// Last updated: 8/12/2026, 9:50:11 AM
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
14    int sumNumbers(TreeNode* root) {
15        stack<pair<TreeNode*,int>> st;
16        st.push({root,0});
17        int sum=0;
18        while(!st.empty()){
19            auto node=st.top().first;
20            int curr=st.top().second;
21            st.pop();
22            curr=curr*10+node->val;
23            if(!node->left && !node->right){
24                sum+=curr;
25            }
26            if(node->left){
27                st.push({node->left,curr});
28            }
29            if(node->right){
30                st.push({node->right,curr});
31            }
32        }
33        return sum;
34    }
35};
36
37class Solution1 {
38public:
39    void trav(TreeNode* root, int &ans, int sum){
40        if(root==NULL){
41            return;
42        }
43        sum=sum*10+root->val;
44        if(!root->left && !root->right){
45            ans+=sum;
46            return;
47        }
48        trav(root->left,ans,sum);
49        trav(root->right,ans,sum);
50    }
51    int sumNumbers(TreeNode* root) {
52        int ans=0;
53        int sum=0;
54        trav(root,ans,sum);
55        return ans;
56    }
57};