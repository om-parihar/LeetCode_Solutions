// Last updated: 9/1/2026, 3:15:54 PM
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
14    void ino(TreeNode* root, vector<int> &inorder){
15        if(root==NULL){
16            return;
17        }
18        ino(root->left,inorder);
19        inorder.push_back(root->val);
20        ino(root->right,inorder);
21    }
22    TreeNode* build(vector<int>& inorder, int low, int high) {
23        if (low > high)
24            return NULL;
25
26        int mid = low + (high - low) / 2;
27
28        TreeNode* root = new TreeNode(inorder[mid]);
29
30        root->left = build(inorder, low, mid - 1);
31        root->right = build(inorder, mid + 1, high);
32
33        return root;
34    }
35
36    TreeNode* balanceBST(TreeNode* root) {
37        vector<int> inorder;
38
39        ino(root, inorder);
40
41        return build(inorder, 0, inorder.size() - 1);
42    }
43};