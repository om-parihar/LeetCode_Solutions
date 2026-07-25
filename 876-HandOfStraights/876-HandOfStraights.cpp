// Last updated: 7/25/2026, 10:58:35 PM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0) return 0;
        map<int,int> mp;
        for(auto it:hand){
            mp[it]++;
        }
        while(!mp.empty()){
            int start=mp.begin()->first;
            for(int j=0;j<groupSize;j++){
                int curr=start+j;
                if(mp.find(curr)==mp.end()){
                    return false;
                }
                mp[curr]--;
                if(mp[curr]==0){
                    mp.erase(curr);
                }
            }
        }
        return true;
    }
};