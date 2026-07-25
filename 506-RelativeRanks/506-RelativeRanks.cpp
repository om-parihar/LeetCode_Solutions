// Last updated: 7/25/2026, 10:59:21 PM
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string> rank;
        rank.push_back("Gold Medal");
        rank.push_back("Silver Medal"); 
        rank.push_back("Bronze Medal"); 
        for(int i=4;i<=n;i++){
            rank.push_back(to_string(i));
        }
        int a=0;
        vector<int> fre;
        vector<string> ans(n);
        fre=score;
        sort(fre.rbegin(),fre.rend());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fre[i]==score[j]){
                    ans[j]=rank[a];
                    a++;
                    break;
                }
            }
        }
        return ans;
    }
};