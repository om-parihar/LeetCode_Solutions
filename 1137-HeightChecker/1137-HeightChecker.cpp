// Last updated: 7/25/2026, 10:57:45 PM
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        int sum=0;
        vector<int> res(n);
        res=heights;
        sort(res.begin(),res.end());
        for(int i=0;i<n;i++){
            if(res[i]!=heights[i]){
                sum++;
            }
        }
        return sum;
    }
};