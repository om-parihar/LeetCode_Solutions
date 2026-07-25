// Last updated: 7/25/2026, 10:57:59 PM
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(int i=1;i<=n;i++){
            int p=0,x=0;
            for(vector<int> &t : trust){
                if(t[0]==i){ 
                    p++;
                    break;
                }
                if(t[1]==i) x++;
            }
            if(p==0 && x==n-1) return i;
        }
        return -1;
    }
};