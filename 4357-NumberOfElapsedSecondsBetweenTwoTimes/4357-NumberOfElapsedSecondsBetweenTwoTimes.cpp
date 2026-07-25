// Last updated: 7/25/2026, 10:56:04 PM
class Solution {
public:
    int secon(string t){
        int h=stoi(t.substr(0,2));
        int m=stoi(t.substr(3,2));
        int s=stoi(t.substr(6,2));
        return h*3600+m*60+s;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return abs(secon(endTime)-secon(startTime));
    }
};