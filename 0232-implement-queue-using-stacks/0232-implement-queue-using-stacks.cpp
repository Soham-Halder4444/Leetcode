class MyQueue {
public:
    #include<stack>
    stack<int>s;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        stack<int>s2;
        while(s.size()>1){
            int x=s.top();
            s.pop();
            s2.push(x);
        }
        int val=s.top();
        s.pop();
        while(!s2.empty()){
            int x=s2.top();
            s2.pop();
            s.push(x);
        }
        return val;
    }
    
    int peek() {
        stack<int>s2;
        while(s.size()>1){
            int x=s.top();
            s.pop();
            s2.push(x);
        }
        int val=s.top();
        s.pop();
        s2.push(val);
        while(!s2.empty()){
            int x=s2.top();
            s2.pop();
            s.push(x);
        }
        return val;
    }
    
    bool empty() {
        if(s.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */