// Last updated: 7/25/2026, 11:00:30 PM
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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* temp=head;
        while(temp!=NULL){
         
            res.push_back(temp->val);
             temp=temp->next;
        }
        int n=res.size();
        for(int i=0;i<n/2;i++){
            if(res[i]!=res[n-1-i]){
                return false;
            }
        }
        return true;
    }
};