// Last updated: 7/25/2026, 10:58:20 PM
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;
        int start=0,end=0,ans=0;
        while(end<n){
            mp[fruits[end]]++;
            while(mp.size()>2){
                mp[fruits[start]]--;
                if(mp[fruits[start]]==0){
                    mp.erase(fruits[start]);
                }
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};