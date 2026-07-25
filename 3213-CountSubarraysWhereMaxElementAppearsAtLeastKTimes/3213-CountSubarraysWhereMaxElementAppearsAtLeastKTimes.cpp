// Last updated: 7/25/2026, 10:56:26 PM
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxEle=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxEle){
                maxEle=nums[i];
            }
        }
        int start=0,end=0;
        long long len=0;
        long long cnt=0;
        while(end<n){
            if(nums[end]==maxEle){
                cnt++;
            }
            while(cnt==k){
                len+=(n-end);
                if(nums[start]==maxEle){
                    cnt--;
                }
                start++;
            }
            end++;
        }
        return len;
    }
};