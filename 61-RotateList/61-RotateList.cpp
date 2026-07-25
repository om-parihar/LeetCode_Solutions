// Last updated: 7/25/2026, 11:02:31 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        vector<int> num;
        ListNode *temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            num.push_back(temp->val);
            temp=temp->next;
        }
        int n=num.size();
        k=k%n;
        int a=n-k;
        ListNode *curr=head;
        for(int i=a;i<n;i++){
            curr->val=num[i];
            curr=curr->next;
        }
        for(int i=0;i<a;i++){
            curr->val=num[i];
            curr=curr->next;
        }
        return head;
    }
};