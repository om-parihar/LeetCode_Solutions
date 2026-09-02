// Last updated: 9/2/2026, 6:30:20 PM
1class Solution {
2public:
3    bool checkValidString(string s) {
4        int low=0,high=0;
5        for(int it: s){
6            if(it=='('){
7                low++;
8                high++;
9            }
10            else if(it==')'){
11                low--;
12                high--;
13            }
14            else{
15                low--;
16                high++;
17            }
18            if(high<0) return false;
19            low=max(0,low);
20        }
21        return low==0;
22    }
23};
24
25
26class Solution1 {
27public:
28    bool checkValidString(string s) {
29        int left=0,star=0;
30        for(int it:s){
31            if(it=='(') left++;
32            else if(it==')'){
33                if(left){
34                    left--;
35                }
36                else if(star){
37                    star--;
38                }
39                else{
40                    return false;
41                }
42            }
43            else{
44                star++;
45            }
46        }
47        return left==0;
48    }
49};