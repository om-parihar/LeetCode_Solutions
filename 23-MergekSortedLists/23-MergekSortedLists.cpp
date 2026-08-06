// Last updated: 8/6/2026, 10:27:41 PM
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
11// class Solution {
12// public:
13//     void merge(priority_queue<int,vector<int>,greater<int>>&p,ListNode* arr){
14//         while(arr){
15//             p.push(arr->val);
16//             arr=arr->next;
17//         }
18//     }
19//     ListNode* mergeKLists(vector<ListNode*>& lists) {
20//         if(lists.empty()) return NULL;
21//         int n=lists.size();
22//         priority_queue<int,vector<int>,greater<int>> p;
23//         for(int i=0;i<n;i++){
24//             merge(p,lists[i]);
25//         }
26//         ListNode* head=new ListNode();
27//         ListNode* tail=head;
28//         while(!p.empty()){
29//             tail->next=new ListNode(p.top());
30//             tail=tail->next;
31//             p.pop();
32//         }
33//         return head->next;
34//     }
35// };
36
37class Solution {
38public:
39    ListNode* mergeKLists(vector<ListNode*>& lists) {
40        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
41        for(auto it: lists){
42            if(it) pq.push({it->val,it});
43        }
44        ListNode* dummy=new ListNode(0);
45        ListNode* temp=dummy;
46        while(!pq.empty()){
47            ListNode* node=pq.top().second;
48            temp->next=node;
49            temp=temp->next;
50            if (node->next) {
51                pq.push({node->next->val, node->next});
52            }
53            pq.pop();
54        }
55        return dummy->next;
56    }
57};