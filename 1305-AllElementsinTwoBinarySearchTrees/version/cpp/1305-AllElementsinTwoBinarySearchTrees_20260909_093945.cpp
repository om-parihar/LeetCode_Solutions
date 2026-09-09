// Last updated: 9/9/2026, 9:39:45 AM
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
14    void inorder(TreeNode* r, vector<int>& x){
15        if(r==NULL){
16            return;
17        }
18        inorder(r->left,x);
19        x.push_back(r->val);
20        inorder(r->right,x);
21    }
22    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
23        vector<int> a;
24        vector<int> b;
25        inorder(root1,a);
26        inorder(root2,b);
27        vector<int> ans;
28        int i=0,j=0;
29        while(i<a.size() && j<b.size()){
30            if(a[i]<b[j]){
31                ans.push_back(a[i]);
32                i++;
33            }
34            else{
35                ans.push_back(b[j]);
36                j++;
37            }
38        }
39        while(i<a.size()){
40            ans.push_back(a[i]);
41            i++;
42        }
43        while(j<b.size()){
44            ans.push_back(b[j]);
45            j++;
46        }
47        return ans;
48    }
49};