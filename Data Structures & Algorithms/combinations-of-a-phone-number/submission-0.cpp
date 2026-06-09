class Solution {
public:
    vector<string> keypad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        string out;
        backtrack(digits,out,0);
        return res;
    }

    void backtrack(string digits, string &out,int i){
        if(i==digits.length()){
            res.push_back(out);
            return;
        }

        int digit = digits[i]-'0';
        if(digit==0 || digit==1){
            backtrack(digits,out,i+1);
        }

        for(int k=0;k<keypad[digit].size();k++){
            out.push_back(keypad[digit][k]);
            backtrack(digits,out,i+1);
            out.pop_back();

        }

        return;
    }
};
