// Last updated: 9/10/2026, 9:44:44 PM
1class Solution {
2public:
3    void count(int i, string& num, long long target, string temp,
4               vector<string>& all, long long value, long long prev) {
5        
6        if(i == num.size()) {
7            if(value == target)
8                all.push_back(temp);
9            return;
10        }
11
12        long long curr = 0;
13
14        for(int j = i; j < num.size(); j++) {
15            if(j > i && num[i] == '0')
16                break;
17
18            curr = curr * 10 + (num[j] - '0');
19            string part = num.substr(i, j - i + 1);
20
21            if(i == 0) {
22                count(j + 1, num, target, part, all, curr, curr);
23            }
24            else {
25                count(j + 1, num, target, temp + "+" + part,
26                      all, value + curr, curr);
27
28                count(j + 1, num, target, temp + "-" + part,
29                      all, value - curr, -curr);
30
31                count(j + 1, num, target, temp + "*" + part,
32                      all, value - prev + prev * curr, prev * curr);
33            }
34        }
35    }
36
37    vector<string> addOperators(string num, int target) {
38        vector<string> all;
39        count(0, num, target, "", all, 0, 0);
40        return all;
41    }
42};