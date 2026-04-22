class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            if(m.find(t[i])==m.end() || m[t[i]]==0){
                return false;
            }
            else{
                m[t[i]]--;
            }
        }
        return true;
    }
};
