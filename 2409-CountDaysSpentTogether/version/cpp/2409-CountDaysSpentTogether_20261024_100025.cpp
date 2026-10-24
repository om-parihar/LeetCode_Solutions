// Last updated: 10/24/2026, 10:00:25 AM
1class Solution {
2public:
3    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
4        int arr[12]={31,28,31,30,31,30,31,31,30,31,30,31};
5
6        int alicemonth=(arriveAlice[0]-'0')*10+(arriveAlice[1]-'0');
7        int aliceday=(arriveAlice[3]-'0')*10+(arriveAlice[4]-'0');
8        int bobmonth=(arriveBob[0]-'0')*10+(arriveBob[1]-'0');
9        int bobday=(arriveBob[3]-'0')*10+(arriveBob[4]-'0');
10
11        int monthalice=(leaveAlice[0]-'0')*10+(leaveAlice[1]-'0');
12        int dayalice=(leaveAlice[3]-'0')*10+(leaveAlice[4]-'0');
13        int monthbob=(leaveBob[0]-'0')*10+(leaveBob[1]-'0');
14        int daybob=(leaveBob[3]-'0')*10+(leaveBob[4]-'0');
15        
16        int alicearrive=0;
17        for(int i=0;i<alicemonth-1;i++){
18            alicearrive+=arr[i];
19        }
20        alicearrive+=aliceday;
21        int bobarrive=0;
22        for(int i=0;i<bobmonth-1;i++){
23            bobarrive+=arr[i];
24        }
25        bobarrive+=bobday;
26        int aliceleave=0;
27        for(int i=0;i<monthalice-1;i++){
28            aliceleave+=arr[i];
29        }
30        aliceleave+=dayalice;
31        int bobleave=0;
32        for(int i=0;i<monthbob-1;i++){
33            bobleave+=arr[i];
34        }
35        bobleave+=daybob;
36        
37        int start=max(alicearrive,bobarrive);
38        int end=min(aliceleave,bobleave);
39        return max(0,end-start+1);
40    }
41};