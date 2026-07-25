// Last updated: 7/25/2026, 10:56:46 PM
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(colors[n-1]!=colors[i]){
                ans=max(ans,abs(i-(n-1)));
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(colors[0]!=colors[i]){
                ans=max(ans,abs(i-0));
                break;
            }
        }
        return ans;
    }
};