// Last updated: 7/25/2026, 11:02:44 PM
class Solution {
public:
    double check(double x, long long n){
        if(n==0){
            return 1; 
        }

        double half=check(x,n/2);
        if(n%2==0){
            return half*half;
        }else{
            return x*half*half;
        }
    }

public:
    double myPow(double x, int n) {
        long long N=n;
        if(N<0){
            N=-N;;
            x=1/x;
        }
        return check(x,N);
    }
};