// Last updated: 7/25/2026, 10:59:43 PM
class Solution {
public:
    bool split(vector<int> &nums, int mid, int k){
        int sum=0;
        int i=0;
        int cnt=1;
        while(i<nums.size()){
            if(nums[i]>mid) return false;
            if(nums[i]+sum>mid){
                sum=nums[i];
                cnt++;
            }
            else{
                sum+=nums[i];
            }
            i++;
        }
        if(cnt>k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int i=*max_element(nums.begin(),nums.end());
        if(k>n) return -1;
        int j;
        for(int a=0;a<n;a++){
            j+=nums[a];
        }
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(split(nums,mid,k)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};