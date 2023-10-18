int precedence(char c) {
        if (c == '+' || c == '-') 
           return 1;
        else if ( c == '/' || c == '*')
           return 2;
        else if (c == '^') 
           return 3;
        else 
           return -1;
    }
    
    string infixToPostfix(string s) {
        // Your code here
        stack<char> st;
        string ans;
        
        for (int i = 0; i < s.size(); i++) {
            if ( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )
               ans += s[i];
            else if (s[i] == '(') 
               st.push(s[i]);
            else if (s[i] == ')') {
                 while (st.top() != '(') {
                     ans += st.top();
                     st.pop();
                 }
                 st.pop();
            }
            else {
                  while (  !st.empty()  &&  (precedence(s[i]) <= precedence(st.top()))  ) {
                      ans += st.top();
                      st.pop();
                  }
                  st.push(s[i]);
            }
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
