// Last updated: 7/25/2026, 10:56:20 PM
class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        if(n<=1) return 0;
        int sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum+abs((s[i]-'a')-(s[i+1]-'a'));
        }
        return sum;
    }
};