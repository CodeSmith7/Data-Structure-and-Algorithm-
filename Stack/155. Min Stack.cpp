class MinStack {
public:
    stack<int> st;
    void solve (stack<int> & st, int  &mini) {
        if (st.empty() == 1) {
            return;
        }

        int ele = st.top();
        mini = min(ele, mini);
        st.pop();
        solve (st, mini);
        st.push(ele);
    }
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int ele = st.top();
        return ele;
    }
    
    int getMin() {
        int mini = INT_MAX;
        solve (st, mini);
        return mini;
    }
};

//in O(2*n) space  
class MinStack {
public:
    stack<pair<int,int>> st;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if ( st.empty ()) {
            st.push({val, val});
        } else {
            int ele = st.top().second;
            ele = min(ele, val);
            st.push({val,ele});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int ele = st.top().first;
        return ele;
    }
    
    int getMin() {
       return st.top().second;
    }
};


//optimized approach 

class MinStack {
public:
    stack<long> st;
    long mini;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            mini = val;
            st.push(val);
        } else {
            if (val >= mini) {
                st.push(val);
            } else {
                st.push(2L * val - mini);
                mini = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long x = st.top();
        st.pop();

        if (x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long x = st.top();
        if (x >= mini) return (int)x;
        return (int)mini;
    }

    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
