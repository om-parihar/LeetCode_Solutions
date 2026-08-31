// Last updated: 8/31/2026, 4:26:27 PM
class Solution {
public:
    bool sumGame(string num) {
        int leftsum=0;
        int rightsum=0;
        int leftQ=0,rightQ=0;
        int n=num.size();
        for(int i=0;i<n/2;i++){
            if(num[i]!='?'){
                leftsum+=num[i]-'0';
            }
            else{
                leftQ++;
            }
        }
        for(int i=n/2;i<n;i++){
            if(num[i]!='?'){
                rightsum+=num[i]-'0';
            }
            else{
                rightQ++;
            }
        }
        if((leftQ + rightQ) % 2 == 1)
            return true;
        if(leftQ > rightQ) {
            leftsum += (leftQ - rightQ) / 2 * 9;
        }
        else {
            rightsum += (rightQ - leftQ) / 2 * 9;
        }

        return leftsum != rightsum;
    }
};