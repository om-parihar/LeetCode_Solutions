// Last updated: 10/13/2026, 10:07:03 PM
1class Solution {
2public:
3    long long maxAlternatingSum(vector<int>& nums) {
4        int n=nums.size();
5        for(int i=0;i<n;i++){
6            if(nums[i]<0){
7                nums[i]=abs(nums[i]);
8            }
9        }
10        sort(nums.rbegin(),nums.rend());
11        long long oddsum=0;
12        long long evensum=0;
13        int a=0;
14        if(n%2==0){
15            a=n/2;
16        }
17        else{
18            a=(n/2)+1;
19        }
20        for(int i=0;i<n;i++){
21            if(i<a){
22                evensum+=(nums[i]*nums[i]);
23            }
24            else{
25                oddsum+=(nums[i]*nums[i]);
26            }
27        }
28        return evensum-oddsum;
29    }
30};