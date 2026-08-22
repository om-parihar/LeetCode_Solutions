// Last updated: 8/22/2026, 10:09:26 PM
1class Solution {
2public:
3    int findDuplicate(vector<int>& nums) {
4        int slow=nums[0];
5        int fast=nums[0];
6        do{
7            slow=nums[slow];
8            fast=nums[nums[fast]];
9        } while(slow!=fast);
10        slow=nums[0];
11        while(slow!=fast){
12            slow=nums[slow];
13            fast=nums[fast];
14        }
15        return slow;
16    }
17};
18
19class Solution1 {
20public:
21    int findDuplicate(vector<int>& nums) {
22        int n=nums.size();
23        sort(nums.begin(),nums.end());
24        for(int i=1;i<n;i++){
25            if(nums[i]==nums[i-1]){
26                return nums[i];
27            }
28        }
29        return -1;
30    }
31};