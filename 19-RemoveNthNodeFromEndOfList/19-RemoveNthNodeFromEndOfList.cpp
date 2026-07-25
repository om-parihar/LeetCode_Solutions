// Last updated: 7/25/2026, 11:03:10 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp;
        temp=head;
        int count=0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        count=count-n;
        ListNode *curr=head, *prev=NULL;
        curr=head;
        if(count==0){
            temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        while(count){
            prev=curr;
            curr=curr->next;
            count--;
        }
        prev->next=curr->next;
        delete curr;
        return head;
    }
};