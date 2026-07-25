// Last updated: 7/25/2026, 11:02:15 PM
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return true;
            }
        }
        return false;
    }
};