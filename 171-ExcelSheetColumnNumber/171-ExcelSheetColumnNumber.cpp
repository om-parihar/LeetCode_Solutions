// Last updated: 7/25/2026, 11:01:10 PM
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum=0;
        for(char c:columnTitle){
            sum*=26; 
            sum+=(c-'A'+1);
        }
        return sum;
    }
};