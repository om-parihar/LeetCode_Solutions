// Last updated: 7/25/2026, 10:59:49 PM
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        int freq[256]={0};
        for(char c:s){
            freq[c]++;
        }
        for(int i=0;i<n;i++){
            if(freq[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};