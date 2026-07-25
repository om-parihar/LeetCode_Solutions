// Last updated: 7/25/2026, 10:57:21 PM
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int totalSum=0;
        for(int i=0;i<n;i++){
            totalSum+=cardPoints[i];
        }
        int windowSize=n-k;
        int windowSum=0;
        for(int i=0;i<windowSize;i++){
            windowSum+=cardPoints[i];
        }
        int minWindow=windowSum;
        for(int i=windowSize;i<n;i++){
            windowSum+=cardPoints[i];
            windowSum-=cardPoints[i-windowSize];
            minWindow=min(minWindow,windowSum);
        }
        return totalSum-minWindow;
    }
};