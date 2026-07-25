// Last updated: 7/25/2026, 11:00:26 PM
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
    void deleteNode(ListNode* node) {
        ListNode* it=node->next;
        node->val=it->val;
        node->next=it->next;
        delete it;
    }
};