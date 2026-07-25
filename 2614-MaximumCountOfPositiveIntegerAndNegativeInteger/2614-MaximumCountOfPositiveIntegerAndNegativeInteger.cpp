// Last updated: 7/25/2026, 10:56:33 PM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int arr[2];
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                arr[0]++;
            }
            else if(nums[i]>0){
                arr[1]++;
            }
        }
        if(arr[0]>arr[1]){
            return arr[0];
        }
        else if(arr[0]<arr[1]){
            return arr[1];
        }
        else {
            return arr[0];
        }
    }
};