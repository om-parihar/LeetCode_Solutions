// Last updated: 7/25/2026, 10:57:27 PM
class Solution {
public:
    int numberOfSteps(int num) {
        int cnt=0;
        while(num){
            if(num%2==0){
                num=num/2;
            }
            else{
                num=num-1;
            }
            cnt=cnt+1;
        }
        return cnt;
    }
};