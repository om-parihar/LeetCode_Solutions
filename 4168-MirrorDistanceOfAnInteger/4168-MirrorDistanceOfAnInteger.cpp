// Last updated: 7/25/2026, 10:55:57 PM
class Solution {
public:
    long long reverse(long long num){
        long long rev=0;
        while(num){
            int x=num%10;
            rev=rev*10+x;
            num=num/10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        long long rev=reverse(n);
        return abs(rev-n);
    }
};