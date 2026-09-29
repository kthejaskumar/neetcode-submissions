class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        for(int num : digits){
            string a = to_string(num);
            s+=a;
        }

        long long int val = stol(s);
        val = val + 1;
        vector<int> ans;
        string b = to_string(val);

        for(int i=0;i<b.length();i++){
            int temp = b[i] - '0';
            ans.push_back(temp);
        }
        return ans;
    }
};
