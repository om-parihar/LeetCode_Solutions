// Last updated: 7/25/2026, 11:02:27 PM
class Solution {
public:
    int mySqrt(int x) {
        if(x==0){
            return 0;
        }
        long long s=1;
        long long e=x;
        int ans=0;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(mid*mid==x){
                return mid;
            }
            if(mid*mid<x){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return ans;
    }
};