// Last updated: 7/25/2026, 11:01:17 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *c1=headA;
        ListNode *c2=headB;
        int curr1=0,curr2=0;
        while(c1!=NULL){
            curr1++;
            c1=c1->next;
        }
        while(c2!=NULL){
            curr2++;
            c2=c2->next;
        }
        int diff=0;
        if(curr1>curr2) diff=curr1-curr2;
        else diff=curr2-curr1;
        c1=headA;
        c2=headB;
        if(curr1>curr2){
            while(diff!=0){
                c1=c1->next;
                diff--;
            }
        }
        else{
            while(diff!=0){
                c2=c2->next;
                diff--;
            }
        }
        while(c1!=c2){
            c1=c1->next;
            c2=c2->next;
        }
        return c1;
    }
};