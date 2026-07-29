// Last updated: 7/29/2026, 12:06:34 PM
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
13    ListNode* insertionSortList(ListNode* head) {
14        vector<int> temp;
15        ListNode* t=head;
16        while(t){
17            temp.push_back(t->val);
18            t=t->next;
19        }
20        for (int i = 1; i < temp.size(); i++) {
21            int key = temp[i];
22            int j = i - 1;
23
24            while (j >= 0 && temp[j] > key) {
25                temp[j + 1] = temp[j];
26                j--;
27        }
28
29        temp[j + 1] = key;
30    }
31        ListNode* root=new ListNode(0);
32        ListNode* a=root;
33        for(int i=0;i<temp.size();i++){
34            a->next=new ListNode(temp[i]);
35            a=a->next;
36        }
37        return root->next;
38    }
39};