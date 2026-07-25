// Last updated: 7/25/2026, 10:58:10 PM
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        return fib(n-1)+fib(n-2);
    }
};