// Last updated: 11/26/2026, 1:49:10 PM
1class Solution {
2public:
3    bool canAliceWin(int n) {
4        int stones = 10;
5        bool alice = true;
6
7        while (n >= stones) {
8            n -= stones;
9            alice = !alice;
10            stones--;
11        }
12
13        return !alice;
14    }
15};