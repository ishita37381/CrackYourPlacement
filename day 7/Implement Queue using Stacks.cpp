class MyQueue {
    stack<int>s1;
    stack<int>s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s1.empty() and s2.empty())return -1;
        if(s2.empty()){
            while(!s1.empty()){
              s2.push(s1.top());
              s1.pop();
            }
        }
        int pop_val=s2.top();
        s2.pop();
        return pop_val;
    }
    
    int peek() {
        if(s1.empty() and s2.empty())return -1;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top_val=s2.top();
        return top_val;
    }
    
    bool empty() {
        if(s1.empty() and s2.empty())return true;
        else return false;
    }
};
