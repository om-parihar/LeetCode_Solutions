// Last updated: 9/15/2026, 11:38:02 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11/**
12 * Definition for a binary tree node.
13 * struct TreeNode {
14 *     int val;
15 *     TreeNode *left;
16 *     TreeNode *right;
17 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
18 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
19 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
20 * };
21 */
22class Solution {
23public:
24    TreeNode* solve(vector<int>& nums, int left,int right){
25        if(left>right) return NULL;
26        int mid=(left+right)/2;
27        TreeNode* root=new TreeNode(nums[mid]);
28        root->left=solve(nums,left,mid-1);
29        root->right=solve(nums,mid+1,right);
30        return root;
31    }
32    TreeNode* sortedListToBST(ListNode* head) {
33        vector<int> inorder;
34        while(head){
35            inorder.push_back(head->val);
36            head=head->next;
37        }
38        sort(inorder.begin(),inorder.end());
39        return solve(inorder,0,inorder.size()-1);
40    }
41};