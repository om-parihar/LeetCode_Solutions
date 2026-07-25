// Last updated: 7/25/2026, 10:58:45 PM
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int a=jewels.size();
        int b=stones.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(i<a){
            if(j==b){
                i++;
                j=0;
            }
            if(jewels[i]==stones[j]){
                cnt++;
            }
            j++;
        }
        return cnt;
    }
};