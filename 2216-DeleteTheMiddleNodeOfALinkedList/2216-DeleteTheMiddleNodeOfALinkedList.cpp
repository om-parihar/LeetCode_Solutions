// Last updated: 7/25/2026, 10:56:44 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            temp=temp->next;
            cnt++;
        }
        temp=head;
        int idx=(cnt/2);
        int c=0;
        while(c!=idx-1){
            temp=temp->next;
            c++;
        }
        ListNode* it=temp->next;
        temp->next=temp->next->next;
        delete it;
        return head;
    }
};