// Last updated: 7/25/2026, 10:58:53 PM
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev=n%2;
        n=n/2;
        while(n>0){
            int curr=n%2;
            if(curr==prev) return 0;
            prev=curr;
            n=n/2;
        }
        return 1;
    }
};