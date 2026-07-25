// Last updated: 7/25/2026, 10:59:29 PM
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int a=g.size();
        int b=s.size();
        int sum=0;
        int i=0;
        int j=0;
        while(i<a && j<b){
            if(g[i]<=s[j]){
                sum++;
                i++;
            }
            j++;
        }
        return sum;
    }
};