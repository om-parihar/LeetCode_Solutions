// Last updated: 9/6/2026, 10:05:58 PM
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
11
12class Solution {
13public:
14    ListNode* reverseKGroup(ListNode* head, int k) {
15        ListNode* node = head;
16        for(int i = 0; i < k; i++){
17            if(node == nullptr) return head; 
18            node = node->next;
19        }
20
21        ListNode* prev = reverseKGroup(node, k);
22        ListNode* curr = head;
23        for(int i = 0; i < k; i++){
24            ListNode* next = curr->next;
25            curr->next = prev;
26            prev = curr;
27            curr = next;
28        }
29        return prev;
30    }
31};
32
33class Solution1 {
34public:
35    void swapp(int i, int j, vector<int>& nodes){
36        while(i<j){
37            swap(nodes[i],nodes[j]);
38            i++;
39            j--;
40        }
41    }
42    ListNode* reverseKGroup(ListNode* head, int k) {
43        vector<int> nodes;
44        while(head!=NULL){
45            nodes.push_back(head->val);
46            head=head->next;
47        }
48        int n=nodes.size();
49        for(int i=0;i+k<=n;i=i+k){
50            swapp(i,i+k-1,nodes);
51        }
52        ListNode* dummy=new ListNode();
53        ListNode* temp=dummy;
54        for(int i=0;i<n;i++){
55            temp->next=new ListNode(nodes[i]);
56            temp=temp->next;
57        }
58        return dummy->next;
59    }
60};