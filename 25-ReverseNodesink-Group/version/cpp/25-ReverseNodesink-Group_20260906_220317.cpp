// Last updated: 9/6/2026, 10:03:17 PM
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
13    void swapp(int i, int j, vector<int>& nodes){
14        while(i<j){
15            swap(nodes[i],nodes[j]);
16            i++;
17            j--;
18        }
19    }
20    ListNode* reverseKGroup(ListNode* head, int k) {
21        vector<int> nodes;
22        while(head!=NULL){
23            nodes.push_back(head->val);
24            head=head->next;
25        }
26        int n=nodes.size();
27        for(int i=0;i+k<=n;i=i+k){
28            swapp(i,i+k-1,nodes);
29        }
30        ListNode* dummy=new ListNode();
31        ListNode* temp=dummy;
32        for(int i=0;i<n;i++){
33            temp->next=new ListNode(nodes[i]);
34            temp=temp->next;
35        }
36        return dummy->next;
37    }
38};