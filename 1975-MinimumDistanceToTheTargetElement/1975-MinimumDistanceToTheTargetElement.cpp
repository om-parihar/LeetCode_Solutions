// Last updated: 7/25/2026, 10:56:57 PM
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                mn=min(mn,abs(i-start));
            }
        }
        return mn;
    }
};