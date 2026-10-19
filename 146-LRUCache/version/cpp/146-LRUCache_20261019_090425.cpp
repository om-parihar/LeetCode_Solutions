// Last updated: 10/19/2026, 9:04:25 AM
1class LRUCache {
2private:
3    struct Node{
4        int key;
5        int value;
6        Node* prev;
7        Node* next;
8        Node(int k, int v){
9            key=k;
10            value=v;
11            prev=NULL;
12            next=NULL;
13        }
14    };
15    int capacity;
16    std::unordered_map<int,Node*> mp;
17    Node* head;
18    Node* tail;
19
20    void addNode(Node* node){
21        node->next=head->next;
22        node->prev=head;
23        head->next->prev=node;
24        head->next=node;
25    }
26
27    void removeNode(Node* node){
28        node->prev->next=node->next;
29        node->next->prev=node->prev;
30    }
31
32    void moveToHead(Node* node){
33        removeNode(node);
34        addNode(node);
35    }
36
37    Node* popTail(){
38        Node* res=tail->prev;
39        removeNode(res);
40        return res;
41    }
42
43public:
44    LRUCache(int cap) {
45        capacity=cap;
46        head=new Node(-1,-1);
47        tail=new Node(-1,-1);
48        head->next=tail;
49        tail->prev=head;
50    }
51    
52    int get(int key) {
53        auto it=mp.find(key);
54        if(it==mp.end()){
55           return -1;
56        }
57        Node* node=it->second;
58        moveToHead(node);
59        return node->value;
60    }
61    
62    void put(int key, int value) {
63        auto it=mp.find(key);
64        if(it!=mp.end()){
65            Node* node=it->second;
66            node->value=value;
67            moveToHead(node);
68        }else{
69            Node* newNode = new Node(key,value);
70            mp[key]=newNode;
71            addNode(newNode);
72            if(mp.size()>capacity){
73                Node* tailNode=popTail();
74                mp.erase(tailNode->key);
75                delete tailNode;
76            }
77        }
78    }
79};
80
81/**
82 * Your LRUCache object will be instantiated and called as such:
83 * LRUCache* obj = new LRUCache(capacity);
84 * int param_1 = obj->get(key);
85 * obj->put(key,value);
86 */