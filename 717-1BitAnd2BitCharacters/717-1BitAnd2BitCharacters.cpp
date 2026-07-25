// Last updated: 7/25/2026, 10:58:50 PM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int i=0;
        while(i<n-1){
            if(bits[i]==1){
                i+=2;
            }
            else{
                i+=1;
            }
        }
        return i==n-1;
    }
};