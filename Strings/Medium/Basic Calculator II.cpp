class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int curr = 0;
        char sign = '+';

        for(int i=0; i<s.size();i++){
            if(isdigit(s[i])){
                curr = 10*curr + int(s[i]-'0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1){
                if(sign == '+'){
                    st.push(curr);
                }
                else if(sign == '-'){
                    st.push(-curr);
                }
                else{
                    int num;
                    if(sign == '*'){
                        num = st.top() * curr;
                    }
                    else{
                        num = st.top() / curr;
                    }
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                curr = 0; 
            }
            
        }
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
