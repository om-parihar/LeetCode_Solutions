// Last updated: 7/25/2026, 10:57:15 PM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunk=0;
        int empty=0;
        while(numBottles>0){
            drunk+=numBottles;
            empty+=numBottles;
            numBottles=0;
            int newb=empty/numExchange;
            empty=empty%numExchange;
            numBottles=newb;
        }
        return drunk;
    }
};