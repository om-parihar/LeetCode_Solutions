// Last updated: 7/25/2026, 11:01:14 PM
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n<2) return 0;
        int a=0;
        int i=0;
        while(i<n-1){
            a=max(a,nums[i+1]-nums[i]);
            i++;
        }
        return a;
    }
};