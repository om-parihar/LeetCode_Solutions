// Last updated: 7/25/2026, 11:02:10 PM
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummyless(0);
        ListNode dummygreater(0);
        ListNode *B=&dummyless;
        ListNode *A=&dummygreater;
        while(head!=nullptr){
            if(head->val<x){
                B->next=head;
                B=B->next;
            }
            else{
                A->next=head;
                A=A->next;
            }
            head=head->next;
        }
        A->next=nullptr;
        B->next=dummygreater.next;
        return dummyless.next;
    }
};