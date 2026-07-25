// Last updated: 7/25/2026, 10:58:13 PM
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        int n=deck.size();
        vector<int> ans(n);
        sort(deck.begin(),deck.end());
        for(int i=0;i<n;i++){
            q.push(i);
        }
        for(int i=0;i<n;i++){
            int idx=q.front();
            q.pop();
            ans[idx]=deck[i];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return ans;
    }
};