// Last updated: 7/25/2026, 10:55:59 PM
class Solution {
public:
    int solve(int a, int b){    
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]>mx){
                mx=nums[i];
            }
            ans.push_back(solve(mx,nums[i]));
        }
        sort(ans.begin(),ans.end());
        int a=0,b=ans.size()-1;
        long long as=0;
        while(a<b){
            as+=solve(ans[a],ans[b]);
            a++;
            b--;
        }
        return as;
    }
};