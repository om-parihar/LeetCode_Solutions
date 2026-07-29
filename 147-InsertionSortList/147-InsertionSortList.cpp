// Last updated: 7/29/2026, 12:45:20 PM
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
14    ListNode* insertionSortList(ListNode* head) {
15        if (!head || !head->next)
16            return head;
17
18        ListNode dummy(0);
19        dummy.next = head;
20
21        ListNode* prev = head;
22        ListNode* curr = head->next;
23
24        while (curr) {
25
26            if (curr->val >= prev->val) {
27                prev = curr;
28                curr = curr->next;
29                continue;
30            }
31            prev->next = curr->next;
32
33            ListNode* temp = &dummy;
34            while (temp->next && temp->next->val < curr->val) {
35                temp = temp->next;
36            }
37            curr->next = temp->next;
38            temp->next = curr;
39
40            curr = prev->next;
41        }
42
43        return dummy.next;
44    }
45};