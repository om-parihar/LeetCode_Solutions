// Last updated: 7/25/2026, 11:03:25 PM
class Solution {
public:
    int reverse(int x) {
        int sum=0,rem;
        while(x!=0){
            rem=x%10;
            x=x/10;
            if(sum>INT_MAX/10 || sum<INT_MIN/10){
                return 0;
            }
            sum=sum*10+rem;
        }
        return sum;
    }
};