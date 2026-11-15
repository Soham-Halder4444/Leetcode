class MyStack {
public:
    #include<queue>
    queue<int>q;
    MyStack() {
        
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int>q2;
        int val;
        while(q.size()>1){
            int x = q.front();
            q.pop();
            q2.push(x);
        }
        
        val=q.front();
        q.pop();
        while(!q2.empty()){
            int x=q2.front();
            q2.pop();
            q.push(x);
        }
        return val;
    }
    int top() {
        queue<int>q2;
        int val;
        while(q.size()>1){
            int x = q.front();
            q.pop();
            q2.push(x);
        }
        val=q.front();
        q.pop();
        q2.push(val);
        while(!q2.empty()){
            int x=q2.front();
            q2.pop();
            q.push(x);
        }
        return val;
    }
    
    bool empty() {
        if(q.size()==0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */