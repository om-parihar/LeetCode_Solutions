// Last updated: 7/25/2026, 10:59:37 PM
class Solution {
public:
    int countSegments(string s) {
        int n=s.length();
        int num=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' ' && (i==0 || s[i-1]==' ')){
                num++;
            }
        }
        return num;
    }
};