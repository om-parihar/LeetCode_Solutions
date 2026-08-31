// Last updated: 8/31/2026, 10:28:46 AM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11 class Solution {
12public:
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        if(head==NULL || head->next==NULL) return {-1,-1};
15        ListNode* prev=head;
16        int cnt=1;
17        int f=-1,l=-1;
18        int mn=INT_MAX;
19        head=head->next;
20        ListNode* n=head->next;
21        while(head->next!=NULL){
22            if(prev->val>head->val && n->val>head->val || prev->val<head->val && n->val<head->val){
23                if(f==-1){
24                    f=cnt;
25                } 
26                else{
27                    mn=min(mn,cnt-l);
28                }
29                l=cnt;
30            }
31            prev=head;
32            head=head->next;
33            n=head->next;
34            cnt++;
35        }
36        if(f==l) return {-1,-1};
37        return {mn,l-f};
38    }
39};
40
41class Solution1 {
42public:
43    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
44        if(head==NULL || head->next==NULL) return {-1,-1};
45        vector<int> ans;
46        while(!head==NULL){
47            ans.push_back(head->val);
48            head=head->next;
49        }
50        if(ans.size()<=2) return {-1,-1};
51        vector<int> temp;
52        for(int i=1;i<ans.size()-1;i++){
53            if(ans[i-1]<ans[i] && ans[i+1]<ans[i]){
54                temp.push_back(i+1);
55            }
56            if(ans[i-1]>ans[i] && ans[i+1]>ans[i]){
57                temp.push_back(i+1);
58            }
59        }
60        if(temp.size()<=1) return {-1,-1};
61        int mn=INT_MAX;
62        int mx=INT_MIN;
63        for(int i=0;i<temp.size();i++){
64            for(int j=i+1;j<temp.size();j++){
65                mn=min(mn,(temp[j]-temp[i]));
66                mx=max(mx,(temp[j]-temp[i]));
67            }
68        }
69        return {mn,mx};
70    }
71};