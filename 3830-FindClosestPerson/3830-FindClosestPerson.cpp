// Last updated: 7/25/2026, 10:56:23 PM
class Solution {
public:
    int findClosest(int x, int y, int z) {
        int disx=abs(x-z);
        int disy=abs(z-y);
        if(disx==disy) return 0;
        if(disx>disy) return 2;
        else return 1;
    }
};