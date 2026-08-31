// Last updated: 8/31/2026, 10:46:59 AM
1class MedianFinder {
2    priority_queue<int> left;
3    priority_queue<int,vector<int>,greater<int>> right;
4public:
5    MedianFinder() {
6    }
7    
8    void addNum(int num) {
9        if(left.empty() || num<=left.top()){
10            left.push(num);
11        }
12        else{
13            right.push(num);
14        }
15        if (left.size() > right.size() + 1) {
16            right.push(left.top());
17            left.pop();
18        }
19        else if (right.size() > left.size()) {
20            left.push(right.top());
21            right.pop();
22        }
23    }
24    
25    double findMedian() {
26        if(left.size()==right.size()){
27            return (left.top()+right.top())/2.0;
28        }
29        return left.top();
30    }
31};
32
33/**
34 * Your MedianFinder object will be instantiated and called as such:
35 * MedianFinder* obj = new MedianFinder();
36 * obj->addNum(num);
37 * double param_2 = obj->findMedian();
38 */