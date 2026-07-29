// Last updated: 7/29/2026, 12:05:29 PM
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
20        for(int i=0;i<temp.size();i++){
21            int minIndex=i;
22            for(int j=i+1;j<temp.size();j++){
23                if(temp[minIndex]>temp[j]){
24                    minIndex=j;
25                }
26            }
27            swap(temp[minIndex],temp[i]);
28        }
29        ListNode* root=new ListNode(0);
30        ListNode* a=root;
31        for(int i=0;i<temp.size();i++){
32            a->next=new ListNode(temp[i]);
33            a=a->next;
34        }
35        return root->next;
36    }
37};