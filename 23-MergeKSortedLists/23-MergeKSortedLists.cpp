// Last updated: 7/25/2026, 11:03:04 PM
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
    void merge(priority_queue<int,vector<int>,greater<int>>&p,ListNode* arr){
        while(arr){
            p.push(arr->val);
            arr=arr->next;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n=lists.size();
        priority_queue<int,vector<int>,greater<int>> p;
        for(int i=0;i<n;i++){
            merge(p,lists[i]);
        }
        ListNode* head=new ListNode();
        ListNode* tail=head;
        while(!p.empty()){
            tail->next=new ListNode(p.top());
            tail=tail->next;
            p.pop();
        }
        return head->next;
    }
};