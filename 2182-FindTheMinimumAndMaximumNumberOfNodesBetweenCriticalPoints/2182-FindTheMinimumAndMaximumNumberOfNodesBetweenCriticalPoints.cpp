// Last updated: 8/31/2026, 4:26:13 PM
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL) return {-1,-1};
        ListNode* prev=head;
        int cnt=1;
        int f=-1,l=-1;
        int mn=INT_MAX;
        head=head->next;
        ListNode* n=head->next;
        while(head->next!=NULL){
            if(prev->val>head->val && n->val>head->val || prev->val<head->val && n->val<head->val){
                if(f==-1){
                    f=cnt;
                } 
                else{
                    mn=min(mn,cnt-l);
                }
                l=cnt;
            }
            prev=head;
            head=head->next;
            n=head->next;
            cnt++;
        }
        if(f==l) return {-1,-1};
        return {mn,l-f};
    }
};

class Solution1 {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL) return {-1,-1};
        vector<int> ans;
        while(!head==NULL){
            ans.push_back(head->val);
            head=head->next;
        }
        if(ans.size()<=2) return {-1,-1};
        vector<int> temp;
        for(int i=1;i<ans.size()-1;i++){
            if(ans[i-1]<ans[i] && ans[i+1]<ans[i]){
                temp.push_back(i+1);
            }
            if(ans[i-1]>ans[i] && ans[i+1]>ans[i]){
                temp.push_back(i+1);
            }
        }
        if(temp.size()<=1) return {-1,-1};
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=0;i<temp.size();i++){
            for(int j=i+1;j<temp.size();j++){
                mn=min(mn,(temp[j]-temp[i]));
                mx=max(mx,(temp[j]-temp[i]));
            }
        }
        return {mn,mx};
    }
};