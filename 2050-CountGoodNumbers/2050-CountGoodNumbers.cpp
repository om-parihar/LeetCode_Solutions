// Last updated: 7/25/2026, 10:56:51 PM
class Solution {
public:
    const long long MOD=1e9+7;
    
    long long power(long long b, long long exp){
        long long res=1;

        while(exp>0){
            if(exp%2==1){
                res=(res*b)%MOD;
            }
            b=(b*b)%MOD;
            exp/=2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=(n/2);
        long long evenways=power(5,even);
        long long oddways=power(4,odd);
        return (evenways*oddways)%MOD;
        
    }
};