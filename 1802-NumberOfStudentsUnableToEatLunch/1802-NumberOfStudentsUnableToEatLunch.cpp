// Last updated: 7/25/2026, 10:57:09 PM
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        int m=sandwiches.size();
        stack<int> st;
        queue<int> q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        for(int i=m-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        int cnt=0;
        while(!q.empty() && cnt<q.size()){
            if(st.top()==q.front()){
                q.pop();
                st.pop();
                cnt=0;
            }
            else{
                q.push(q.front());
                q.pop();
                cnt++;
            }
        }
        return q.size();
    }
};