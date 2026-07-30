// Last updated: 7/30/2026, 12:51:44 PM
class Solution {
public:
    int maxProduct(int n) {
        int fLar=0;
        int sLar;
        while(n){
            int num=n%10;
            if(num>=fLar){
                sLar=fLar;
                fLar=num;
            }
            else if(num>sLar){
                sLar=num;
            }
            n=n/10;
        }
        return sLar*fLar;
    }
};