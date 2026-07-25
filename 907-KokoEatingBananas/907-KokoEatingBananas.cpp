// Last updated: 7/25/2026, 10:58:26 PM
class Solution {
public:
    bool solve(int speed,vector<int> &piles,int h){
        long long hours=0;
        for(int pile:piles){
            hours+=(pile+speed-1)/speed;
        }
        if(hours<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(mid,piles,h)){
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