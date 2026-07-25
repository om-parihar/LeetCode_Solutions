// Last updated: 7/25/2026, 11:02:59 PM
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++){
            int first=i,second=0;
            while(second<m){
                if(haystack[first]!=needle[second]){
                    break;
                }
                second++,first++;
            }
            if(second==m){
                return i;
            }
        }
        return -1;
    }
};