class LRUCache {
public:
class Node{
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
Node* head=new Node(-1,-1);
Node* tail=new Node(-1,-1);
int cap;
unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* newNode){
        Node* tmp=head->next;
        newNode->next=tmp;
        newNode->prev=head;
        head->next=newNode;
        tmp->prev=newNode;
    }
    void deleteNode(Node* head){
        Node* p=head->prev;
        Node* n=head->next;
        p->next=n;
        n->prev=p;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode=mp[key];
            int ans=resNode->val;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curr=mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->next;
    }
};
