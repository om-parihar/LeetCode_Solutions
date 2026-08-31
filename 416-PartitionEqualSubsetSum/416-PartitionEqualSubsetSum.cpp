// Last updated: 8/31/2026, 4:30:56 PM
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return false;
        int mx=accumulate(nums.begin(),nums.end(),0);
        if(mx % 2 != 0)
            return false;
        mx=mx/2;
        vector<vector<bool>> dp(n, vector<bool>(mx+1, false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=mx){
            dp[0][nums[0]]=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=mx;j++){
                bool notake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take||notake;
            }
        }
        return dp[n-1][mx];
    }
};

class Solution2 {
public:
    bool fun(int idx, int target, vector<int> &nums, vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0) return (nums[idx]==target);
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool notake=fun(idx-1,target,nums,dp);
        bool take=false;
        if(nums[idx]<=target){
            take=fun(idx-1,target-nums[idx],nums,dp);
        }
        return dp[idx][target]=take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return false;
        int mx=accumulate(nums.begin(),nums.end(),0);
        if(mx % 2 != 0)
            return false;
        mx=mx/2;
        vector<vector<int>> dp(n+1,vector<int>(mx+1,-1));
        return fun(n-1,mx,nums,dp);
    }
};


class Solution1 {
public:
    bool fun(int idx, int target, vector<int> &nums){
        if(target==0) return true;
        if(idx==0) return (nums[idx]==target);
        bool notake=fun(idx-1,target,nums);
        bool take=false;
        if(nums[idx]<target){
            take=fun(idx-1,target-nums[idx],nums);
        }
        return take || notake;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        return fun(n-1,mx,nums);
    }
};