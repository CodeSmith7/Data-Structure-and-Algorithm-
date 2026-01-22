class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
        } else {
            while ( !s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while ( !s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */



//approach 2 : amortizzed solution where push, peek and pop all in O(1)
class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int val;
        if (!s2.empty()) {
            val = s2.top();
            s2.pop();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
            s2.pop();
        }
        return val;
    }

    int peek() {
        int val;
        if (!s2.empty()) {
            val = s2.top();
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            val = s2.top();
        }
        return val;
    }

    bool empty() {
        return s1.empty() && s2.empty();
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
