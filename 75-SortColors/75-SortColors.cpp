// Last updated: 7/25/2026, 11:02:21 PM
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1,mid=0;
        while(mid<=right){
            if(nums[mid]==0){
                swap(nums[mid],nums[left]);
                left++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[right]);
                right--;
            }
            else{
                mid++;
            }
        }
    }
};