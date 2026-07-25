// Last updated: 7/25/2026, 10:59:54 PM
class Solution {
public:
    bool isPerfectSquare(long num) {
        if(num<0) return false;
        if(num==1 || num==0) return true;
        long l=1,r=num/2;
        while(l<=r){
            long mid=l+(r-l)/2;
            long square=mid*mid;
            if(square==num){
                return true;
            }
            else if(square<num){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
};