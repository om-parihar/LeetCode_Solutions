// Last updated: 7/25/2026, 10:56:01 PM
class Solution {
public:
    static const int MOD=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long curr=k;
        long long ops=0;
        long long ans=0;
        for(int x:nums){
            if(curr<x){
                long long need=(x-curr+k-1)/k;
                __int128 add=(__int128)need*(2LL*ops+need+1);
                add/=2;
                ans=(ans+(long long)(add%MOD))%MOD;
                ops+=need;
                curr+=need*1LL*k;
            }
            curr-=x;
        }
        return (int)ans;
    }
};