// Last updated: 7/25/2026, 10:59:20 PM
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int c=1;
        if(num<=1) return false;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0){
                c+=i;
                if (i * i != num) {
                        c += num / i;
                }
            }
        }
        if(c==num) return true;
        else return false;
    }
};