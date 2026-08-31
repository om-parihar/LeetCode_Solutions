// Last updated: 8/31/2026, 4:32:37 PM
class Solution1 {
public:
    int fun(int idx, vector<int> &n){
        if(idx==0) return n[idx];
        if(idx<0) return 0;
        int take=n[idx]+fun(idx-2,n);
        int notake=0+fun(idx-1,n);
        return max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1) temp1.push_back(nums[i]);
            if(i!=0) temp2.push_back(nums[i]);
        }
        int cnt=max(fun(temp1.size()-1,temp1),fun(temp2.size()-1,temp2));
        return cnt;
    }
};

class Solution2 {
public:
    int fun(int idx, vector<int> &n,vector<int> &dp){
        if(idx==0) return n[idx];
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take=n[idx]+fun(idx-2,n,dp);
        int notake=0+fun(idx-1,n,dp);
        return dp[idx]=max(take,notake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=n-1) temp1.push_back(nums[i]);
            if(i!=0) temp2.push_back(nums[i]);
        }
        int cnt1=fun(temp1.size()-1,temp1,dp);
        fill(dp.begin(),dp.end(),-1);
        int cnt2=fun(temp2.size()-1,temp2,dp);
        return max(cnt1,cnt2);
    }
};

class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
    vector<int> dp(end - start + 1);

    dp[0] = nums[start];

    if(start != end)
        dp[1] = max(nums[start], nums[start + 1]);

    for(int i = 2; i < dp.size(); i++) {
        dp[i] = max(
            nums[start + i] + dp[i-2],
            dp[i-1]
        );
    }

    return dp.back();
}
    int rob(vector<int>& nums) {
    int n = nums.size();

    if(n == 1)
        return nums[0];

    int case1 = solve(nums, 0, n-2);
    int case2 = solve(nums, 1, n-1);

    return max(case1, case2);
}
};