// Last updated: 7/25/2026, 10:57:34 PM
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(auto it:text){
            mp[it]++;
        }
        int b=mp['b'];
        int a=mp['a'];
        int l=mp['l']/2;
        int o=mp['o']/2;
        int n=mp['n'];
        return min({b,a,l,o,n});
    }
};