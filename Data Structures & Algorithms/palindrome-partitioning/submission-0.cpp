class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        backtrack(s,part,0);
        return res;
    }

    void backtrack(string &s, vector<string> &part, int i){
        if(i>=s.length()){
            res.push_back(part);
            return;
        }

        for(int j=i;j<s.length();j++){
            if(ispalindrome(s,i,j)){
                part.push_back(s.substr(i,j-i+1));
                backtrack(s,part,j+1);
                part.pop_back();
            }
        }
    }

    bool ispalindrome(string s,int l,int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;r--;
        }
        return true;
    }
};
