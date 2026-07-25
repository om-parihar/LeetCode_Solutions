// Last updated: 7/25/2026, 10:56:41 PM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        int i=0;
        int sum=original;
        while(i<n){
            if(nums[i]==sum){
                sum=sum*2;
                i=-1;
            }
            i++;
        }
        return sum;
    }
};