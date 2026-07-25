// Last updated: 7/25/2026, 10:57:52 PM
class Solution {
public:
    bool solve(int mid, vector<int> weights,int high,int d){
        int load=0,days=1;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>mid){
                days=days+1;
                load=weights[i];
            }
            else{
                load=load+weights[i];
            }
        }
        if(days<=d) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=0;
        for(int i=0;i<weights.size();i++){
            high+=weights[i];
        }
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,weights,high,days)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};