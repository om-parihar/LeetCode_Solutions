// Last updated: 10/25/2026, 10:22:01 PM
1class Solution1 {
2public:
3    long long subArrayRanges(vector<int>& nums) {
4        int n=nums.size();
5        long long ans=0;
6        for(int i=0;i<n;i++){
7            for(int j=i;j<n;j++){
8                int mx=*max_element(nums.begin()+i,nums.begin()+j+1);
9                int mn=*min_element(nums.begin()+i,nums.begin()+j+1);
10                ans+=(mx-mn);
11            }
12        }
13        return ans;
14    }
15};
16
17class Solution {
18public:
19    long long subArrayRanges(vector<int>& nums) {
20        int n=nums.size();
21        long long ans=0;
22        for(int i=0;i<n;i++){
23            int mx=nums[i];
24            int mn=nums[i];
25            for(int j=i;j<n;j++){
26                mx=max(mx,nums[j]);
27                mn=min(mn,nums[j]);
28                ans+=(mx-mn);
29            }
30        }
31        return ans;
32    }
33};