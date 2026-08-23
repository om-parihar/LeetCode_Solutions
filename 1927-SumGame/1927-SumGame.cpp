// Last updated: 8/23/2026, 9:31:39 AM
1class Solution {
2public:
3    bool sumGame(string num) {
4        int leftsum=0;
5        int rightsum=0;
6        int leftQ=0,rightQ=0;
7        int n=num.size();
8        for(int i=0;i<n/2;i++){
9            if(num[i]!='?'){
10                leftsum+=num[i]-'0';
11            }
12            else{
13                leftQ++;
14            }
15        }
16        for(int i=n/2;i<n;i++){
17            if(num[i]!='?'){
18                rightsum+=num[i]-'0';
19            }
20            else{
21                rightQ++;
22            }
23        }
24        if((leftQ + rightQ) % 2 == 1)
25            return true;
26        if(leftQ > rightQ) {
27            leftsum += (leftQ - rightQ) / 2 * 9;
28        }
29        else {
30            rightsum += (rightQ - leftQ) / 2 * 9;
31        }
32
33        return leftsum != rightsum;
34    }
35};