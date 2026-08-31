// Last updated: 8/31/2026, 4:27:29 PM
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> mp;
        for(auto &it: reservedSeats){
            mp[it[0]].insert(it[1]);
        }
        int cnt=(n-mp.size())*2;
        for(auto &[row, seats]:mp){
            bool left=true;
            bool middle=true;
            bool right=true;
            for(int x=2;x<=5;x++){
                if(seats.count(x)){
                    left=false;
                    break;
                }
            }
            for(int x=4;x<=7;x++){
                if(seats.count(x)){
                    middle=false;
                    break;
                }
            }
            for(int x=6;x<=9;x++){
                if(seats.count(x)){
                    right=false;
                    break;
                }
            }
            if(left&&right){
                cnt+=2;
            }
            else if(left||middle||right){
                cnt+=1;
            }
        }
        return cnt;
    }
};