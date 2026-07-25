// Last updated: 7/25/2026, 10:57:17 PM
class Solution {
public:
    bool solve(vector<int> &bloomDay, int mid, int m,int k){
        long long ans=0;
        long long cnt=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                ans+=cnt/k;
                cnt=0;
            }
        }
        ans+=cnt/k;
        if(ans>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=1LL*m*1LL*k;
        if(val>bloomDay.size()) return -1;
        int l=*min_element(bloomDay.begin(),bloomDay.end());
        int h=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(solve(bloomDay,mid,m,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};