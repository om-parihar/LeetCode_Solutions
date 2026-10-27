// Last updated: 10/27/2026, 11:08:29 PM
1class Solution {
2public:
3    void reverse(vector<int>& ans){
4        int i=0;
5        int j=ans.size()-1;
6        while(i<=j){
7            swap(ans[i],ans[j]);
8            i++;
9            j--;
10        }
11    }
12    vector<int> asteroidCollision(vector<int>& asteroids) {
13        int n=asteroids.size();
14        vector<int> ans;
15        stack<int> st;
16        for(int i=0;i<n;i++){
17            if(asteroids[i]>0){
18                st.push(asteroids[i]);
19            }
20            else{
21                bool alive=true;
22                while(!st.empty() && st.top()>0){
23                    if(st.top()==abs(asteroids[i])){
24                        alive=false;
25                        st.pop();
26                        break;
27                    }
28                    else if(st.top()<abs(asteroids[i])){
29                        st.pop();
30                    }
31                    else{
32                        alive=false;
33                        break;
34                    }
35                }
36                if(alive){
37                    st.push(asteroids[i]);
38                }
39            }
40        }
41        while(!st.empty()){
42            ans.push_back(st.top());
43            st.pop();
44        }
45        if(ans.size()==0) return ans;
46        reverse(ans);
47        return ans;
48    }
49};