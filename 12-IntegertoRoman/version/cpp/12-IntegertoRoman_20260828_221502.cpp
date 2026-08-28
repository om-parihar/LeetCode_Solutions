// Last updated: 8/28/2026, 10:15:02 PM
1class Solution {
2public:
3    string rom(int digit){
4        string s;
5        if(digit==1){
6            s="I";
7        }
8        if(digit==2){
9            s="II";
10        }
11        if(digit==3){
12            s="III";
13        }
14        if(digit==4){
15            s="VI";
16        }
17        if(digit==5){
18            s="V";
19        }
20        if(digit==6){
21            s="IV";
22        }
23        if(digit==7){
24            s="IIV";
25        }
26        if(digit==8){
27            s="IIIV";
28        }
29        if(digit==9){
30            s="XI";
31        }
32        if(digit==10){
33            s="X";
34        }
35        if(digit==20){
36            s="XX";
37        }
38        if(digit==30){
39            s="XXX";
40        }
41        if(digit==40){
42            s="LX";
43        }
44        if(digit==50){
45            s="L";
46        }
47        if(digit==60){
48            s="XL";
49        }
50        if(digit==70){
51            s="XXL";
52        }
53        if(digit==80){
54            s="XXXL";
55        }
56        if(digit==90){
57            s="CX";
58        }
59        if(digit==100){
60            s="C";
61        }
62        if(digit==200){
63            s="CC";
64        }
65        if(digit==300){
66            s="CCC";
67        }
68        if(digit==400){
69            s="DC";
70        }
71        if(digit==500){
72            s="D";
73        }
74        if(digit==600){
75            s="CD";
76        }
77        if(digit==700){
78            s="CCD";
79        }
80        if(digit==800){
81            s="CCCD";
82        }
83        if(digit==900){
84            s="MC";
85        }
86        if(digit==1000){
87            s="M";
88        }
89        if(digit==2000){
90            s="MM";
91        }
92        if(digit==3000){
93            s="MMM";
94        }
95        if(digit==4000){
96            s="VM";
97        }
98        if(digit==5000){
99            s="V";
100        }
101        if(digit==6000){
102            s="MV";
103        }
104        if(digit==7000){
105            s="MMV";
106        }
107        if(digit==8000){
108            s="MMMV";
109        }
110        if(digit==9000){
111            s="XM";
112        }
113        return s;
114    }
115
116    string intToRoman(int num) {
117        string res;
118        int i=1;
119        while(num){
120            int digit=num%10;
121            digit=digit*i;
122            res=res+rom(digit);
123            num=num/10;
124            i=i*10;
125        }
126        reverse(res.begin(),res.end());
127        return res;
128    }
129};