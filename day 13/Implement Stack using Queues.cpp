class MyStack {
    queue<int>q1;
    queue<int>q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.empty()){
            q1.push(x);
        }
        else{
            while(!q1.empty()){
                int data=q1.front();
                q1.pop();
                q2.push(data);
            }
            q1.push(x);
            while(!q2.empty()){
                int val=q2.front();
                q2.pop();
                q1.push(val);
            }
        }
    }
    
    int pop() {
        int ele=q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
    int ele=q1.front();
        
        return ele;
        
    }
    
    bool empty() {
        if(q1.size()==0)return true;
        else return false;
    }
};
