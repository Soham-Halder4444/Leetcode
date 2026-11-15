class MinStack {
public:
    stack<long long> st;
    long long min;

public:
    MinStack() {
    }

    void push(int value) {
        long long val = value;

        if (st.empty()) {
            st.push(val);
            min = val;
        }
        else {
            if (val < min) {
                long long encoded = 2 * val - min;
                st.push(encoded);
                min = val;
            }
            else {
                st.push(val);
            }
        }
    }

    void pop() {
        long long val = st.top();
        st.pop();

        if (val < min) {
            min = 2 * min - val;
        }
    }

    int top() {
        long long val = st.top();

        if (val < min) {
            return (int)min;
        }
        else {
            return (int)val;
        }
    }

    int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */