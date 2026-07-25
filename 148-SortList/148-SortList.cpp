// Last updated: 7/25/2026, 11:01:25 PM
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
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int> ans;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->next;
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode(0);
        ListNode*tail=dummy;
        for(int i=0;i<ans.size();i++){
            tail->next=new ListNode(ans[i]);
            tail=tail->next;
        }
        head=dummy->next;
        return head;
    }
};