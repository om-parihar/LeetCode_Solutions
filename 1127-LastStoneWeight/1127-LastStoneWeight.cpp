// Last updated: 7/25/2026, 10:57:46 PM
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n=stones.size();
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            p.push(stones[i]);
        }
        while(p.size()>1){
            int y=p.top();
            p.pop();
            int x=p.top();
            p.pop();
            if(x!=y){
                y=y-x;
                p.push(y);
            }
        }
        return p.empty()?0:p.top();
    }
};