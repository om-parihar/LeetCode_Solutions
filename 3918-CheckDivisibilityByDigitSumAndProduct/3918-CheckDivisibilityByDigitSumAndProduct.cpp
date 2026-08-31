// Last updated: 8/31/2026, 4:24:59 PM
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int cpy=n;
        int product=1;
        while(cpy){
            int digit=cpy%10;
            sum+=digit;
            product*=digit;
            cpy=cpy/10;
        }
        if(n%(sum+product)==0) return true;
        return false;
    }
};