// Last updated: 9/24/2026, 9:54:17 AM
1class Solution {
2public:
3    int count(int x){
4        int sum=0;
5        while(x){
6            sum+=x%10;
7            x=x/10;
8        }
9        return sum;
10    }
11    int smallestIndex(vector<int>& nums) {
12        int n=nums.size();
13        for(int i=0;i<n;i++) {
14            if(count(nums[i])==i) return i;
15        }
16        return -1;
17    }
18};