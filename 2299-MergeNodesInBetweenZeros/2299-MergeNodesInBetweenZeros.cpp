// Last updated: 7/25/2026, 10:56:40 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int a=0;
        head=head->next;
        while(head){
            if(head->val==0){
                tail->next=new ListNode(a);
                tail=tail->next;
                a=0;
            }
            else{
                a+=head->val;
            }
            head=head->next;
        }
        return dummy->next;
    }
};