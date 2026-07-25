// Last updated: 7/25/2026, 10:58:15 PM
class Solution {
public:
    int atleast(vector<int> &nums,int k){
        int n=nums.size();
        int total=0;
        int start=0,cnt=0;
        for(int end=0;end<n;end++){
            cnt+=nums[end];
            while(cnt>=k){
                total+=(n-end);
                cnt-=nums[start];
                start++;
            }
        }
        return total;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        if(goal==0){
            int ans=0,start=0,zeroes=0;
            for(int end=0;end<n;end++){
                if(nums[end]==1){
                    zeroes=0;
                    start=end+1;
                }
                else{
                    zeroes++;
                    ans+=zeroes;
                }
            }
            return ans;
        }
        int ans=0;
        ans=atleast(nums,goal)-atleast(nums,goal+1);
        return ans;
    }
};