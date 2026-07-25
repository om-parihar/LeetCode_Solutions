// Last updated: 7/25/2026, 11:03:28 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int g=x;
        long sum=0,rem;
        while(x!=0){
            rem=x%10;
            sum=sum*10+rem;
            x=x/10;
        }
        if(sum==g){
            return true;
        }
        else{
            return false;
        }
    }
};