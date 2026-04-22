class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int val=0;
        for(int i=0;i<tokens.size();i++){
            string c = tokens[i];
            if(c!="+" and c!="-" and c!="*" and c!="/"){
                int a = stoi(c);
                s.push(a);
                cout<<"Not Operator - "<<s.top()<<endl;
            }
            else{
                if(c=="+"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int ans = a+b;
                    val+=ans;
                    s.push(ans);
                    cout<<"Operator - "<<s.top()<<endl;
                }
                else if(c=="-"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int ans = b-a;
                    val+=ans;
                    s.push(ans);
                    cout<<"Operator - "<<s.top()<<endl;
                }
                else if(c=="*"){
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int ans = a*b;
                    val+=ans;
                    s.push(ans);
                    cout<<"Operator - "<<s.top()<<endl;
                }
                else{
                    int a = s.top();
                    s.pop();
                    int b = s.top();
                    s.pop();
                    int ans = b/a;
                    val+=ans;
                    s.push(ans);
                    cout<<"Operator - "<<s.top()<<endl;
                }
            }
        }
        return s.top();
    }
};
