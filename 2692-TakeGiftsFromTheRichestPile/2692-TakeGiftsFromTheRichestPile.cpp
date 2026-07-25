// Last updated: 7/25/2026, 10:56:32 PM
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        priority_queue<int> p;
        for(int i=0;i<n;i++){
            p.push(gifts[i]);
        }
        while(k){
            int a=p.top();
            p.pop();
            a=sqrt(a);
            p.push(a);
            k--;
        }
        long long sum=0;
        while(!p.empty()){
            sum+=p.top();
            p.pop();
        }
        return sum;
    }
};