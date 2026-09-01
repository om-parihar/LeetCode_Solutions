// Last updated: 9/1/2026, 3:01:47 PM
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
14    pair<int,int> solve(TreeNode* root, priority_queue<int,vector<int>,greater<int>>& pq, bool& perfect,int k) {
15    if (root == NULL) {
16        perfect = true;
17        return {0, 0};
18    }
19
20    bool leftPerfect, rightPerfect;
21
22    auto left = solve(root->left, pq, leftPerfect, k);
23    auto right = solve(root->right, pq, rightPerfect, k);
24
25    int size = 1 + left.first + right.first;
26    int height = 1 + max(left.second, right.second);
27
28    perfect = leftPerfect &&
29              rightPerfect &&
30              left.second == right.second;
31
32    if (perfect) {
33        if (pq.size() < k) {
34            pq.push(size);
35        }
36        else if (size > pq.top()) {
37            pq.pop();
38            pq.push(size);
39        }
40    }
41
42    return {size, height};
43}
44    int kthLargestPerfectSubtree(TreeNode* root, int k) {
45        if(root==NULL) return 0;
46        priority_queue<int,vector<int>,greater<int>> pq;
47        bool perfect;
48        solve(root,pq,perfect,k);
49        if(k>pq.size()) return -1;
50        return pq.top();
51    }
52};