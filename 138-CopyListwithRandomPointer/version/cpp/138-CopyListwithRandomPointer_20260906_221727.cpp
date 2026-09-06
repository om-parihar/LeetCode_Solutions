// Last updated: 9/6/2026, 10:17:27 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* next;
7    Node* random;
8    
9    Node(int _val) {
10        val = _val;
11        next = NULL;
12        random = NULL;
13    }
14};
15*/
16
17class Solution {
18public:
19    Node* copyRandomList(Node* head) {
20        if(head == nullptr) return nullptr;
21        unordered_map<Node*, Node*> mp;
22        Node* curr = head;
23        while(curr != nullptr){
24            mp[curr] = new Node(curr->val);
25            curr = curr->next;
26        }
27        curr = head;
28        while(curr != nullptr){
29            mp[curr]->next = mp[curr->next];
30            mp[curr]->random = mp[curr->random];
31            curr = curr->next;
32        }
33        return mp[head];
34    }
35};