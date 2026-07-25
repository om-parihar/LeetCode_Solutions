// Last updated: 7/25/2026, 10:56:11 PM
class Solution {
public:
    int gcd(int a,int b){
        while(b){
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum=n*n;
        int evenSum=n*(n+1);
        return gcd(oddSum,evenSum);
    }
};