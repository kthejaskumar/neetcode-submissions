class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string s="";
        backtrack(n,s,0,0,0);
        return res;
    }

    void backtrack(int n, string &s, int idx, int open, int close){
        if(idx==2*n){
            res.push_back(s);
            return;
        }
        if(open<n){
            s+="(";
            backtrack(n,s,idx+1,open+1,close);
            s.pop_back();
        }
        if(close<open){
            s+=")";
            backtrack(n,s,idx+1,open,close+1);
            s.pop_back();
        }
    }
};
