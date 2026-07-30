// Last updated: 7/30/2026, 12:51:54 PM
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int a=min(limit,n);
        int cnt=0;
        for(int i=0;i<=a;i++){
            for(int j=0;j<=a;j++){
                int c=n-(i+j);
                if(c>=0 && c<=limit) cnt++;
            }
        }
        return cnt;
    }
};