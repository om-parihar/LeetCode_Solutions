// Last updated: 10/25/2026, 10:07:13 PM
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
11class Solution {
12public:
13    vector<int> nextLargerNodes(ListNode* head) {
14        vector<int> ans;
15        while(head!=NULL){
16            ListNode* temp=head->next;
17            while(temp!=NULL && temp->val<=head->val){
18                temp=temp->next;
19            }
20            if(temp==NULL || temp->val<=head->val){
21                ans.push_back(0);
22            }
23            else{
24                ans.push_back(temp->val);
25            }
26            head=head->next;
27        }
28        return ans;
29    }
30};