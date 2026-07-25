// Last updated: 7/25/2026, 11:02:53 PM
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int a=0;
        if(n==1){
            if(target>nums[0]){
                return 1;
            }
            else if(target==nums[0]){
                return 0;
            }
            else{
                return 0;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                return i;
            }
        }
        for(int i=0;i<n-1;i++){
            if(nums[i]<target && nums[i+1]>target){
                a=i+1;
            }
            else if(target>nums[n-1]){
                a=n;
            }
        }
        return a;
    }
};