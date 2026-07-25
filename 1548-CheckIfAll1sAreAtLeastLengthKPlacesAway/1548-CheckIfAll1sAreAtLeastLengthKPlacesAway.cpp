// Last updated: 7/25/2026, 10:57:20 PM
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j]==1){
                        if(j-i<=k){
                            return false;
                        }
                        break;
                    }
                }
            }
        }
        return true;
    }
};