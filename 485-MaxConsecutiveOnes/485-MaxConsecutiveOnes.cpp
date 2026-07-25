// Last updated: 7/25/2026, 10:59:28 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxcon=0;
        int Sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                Sum++;
                maxcon=max(maxcon,Sum);
            }
            else{
                Sum=0;
            }
        }
        return maxcon;
    }
};