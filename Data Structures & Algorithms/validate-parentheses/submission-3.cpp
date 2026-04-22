class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch=='[' || ch=='{' || ch=='('){
                st.push(ch);
            }

            if((ch==']' || ch=='}' || ch==')')){
                if((!st.empty()) && ((ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{') || (ch==')' && st.top()=='('))){
                        st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
