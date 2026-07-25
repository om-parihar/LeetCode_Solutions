// Last updated: 7/25/2026, 10:58:39 PM
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0,j=n-1;
        sort(nums.begin(),nums.end());
        while(i<=j){
            int mid=(i+j)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return -1;
    }
};