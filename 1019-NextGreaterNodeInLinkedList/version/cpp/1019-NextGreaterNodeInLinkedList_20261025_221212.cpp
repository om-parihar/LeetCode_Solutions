// Last updated: 10/25/2026, 10:12:12 PM
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
11class Solution1 {
12public:
13    vector<int> nextLargerNodes(ListNode* head) {
14        vector<int> ans;
15        while(head!=NULL){
16            ListNode* temp=head->next;
17            while(temp!=NULL && temp->val<=head->val){
18                temp=temp->next;
19            }
20            if(temp==NULL || temp->val<=head->val){
21                ans.push_back(0);
22            }
23            else{
24                ans.push_back(temp->val);
25            }
26            head=head->next;
27        }
28        return ans;
29    }
30};
31
32
33class Solution {
34public:
35    vector<int> nextLargerNodes(ListNode* head) {
36        vector<int> nums;
37        while(head){
38            nums.push_back(head->val);
39            head=head->next;
40        }
41        int n=nums.size();
42        vector<int> ans(n,0);
43        stack<int> st;
44        for(int i=0;i<n;i++){
45            while(!st.empty() && nums[i]>nums[st.top()]){
46                ans[st.top()]=nums[i];
47                st.pop();
48            }
49            st.push(i);
50        }
51        return ans;
52    }
53};