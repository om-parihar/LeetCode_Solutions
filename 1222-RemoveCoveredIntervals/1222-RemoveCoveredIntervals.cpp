// Last updated: 7/25/2026, 10:57:36 PM
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int m=intervals.size();
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        });
        int largest=INT_MIN;
        int cnt=0;
        for(auto &interval:intervals){
            if(interval[1]>largest){
                cnt++;
                largest=interval[1];
            }
        }
        return cnt;   
    }
};