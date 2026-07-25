// Last updated: 7/25/2026, 10:56:12 PM
class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> fre(26,0);
        int n=s.size();
        int vow=0;
        int con=0;
        vector<int> vowv;
        vector<int> cons;
        for(int i=0;i<n;i++){
            fre[s[i]-'a']++;
        }
        for(int j=0;j<26;j++){
            if(j==0 || j==4 || j==8 || j==14 || j==20){
                vowv.push_back(fre[j]);
            }
            else{
                cons.push_back(fre[j]);
            }
        }
        sort(vowv.begin(),vowv.end());
        sort(cons.begin(),cons.end());
        int a=vowv.size();
        int b=cons.size();
        int c=vowv[a-1]+cons[b-1];
        return c;
    }
};