// Last updated: 7/25/2026, 10:59:41 PM
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN, second = LLONG_MIN, third = LLONG_MIN; 
        int distinctCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == first || num == second || num == third) {
                continue;
            }
            distinctCount++;
            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }
        }
        if (distinctCount < 3) {
            return first;
        }
        return third;
    }
};