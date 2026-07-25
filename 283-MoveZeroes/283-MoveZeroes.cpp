// Last updated: 7/25/2026, 11:00:11 PM
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int pos=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[pos]=nums[i];
                pos++;
            }
        }
        for(int i=pos;i<n;i++){
            nums[i]=0;
        }
    }
};