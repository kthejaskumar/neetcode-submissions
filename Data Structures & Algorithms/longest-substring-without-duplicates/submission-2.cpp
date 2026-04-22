class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int j=0,i=0;
        int length=0;
        int maxlen = 0;
        while(j<s.size()){
            char ch = s[j];
            if(m.find(ch)!=m.end()){
                i = max(i,m[ch]+1);
                length = j-i;
            }
            m[ch]=j;
            length++;
            j++;
            maxlen = max(maxlen,length);
        }
        return maxlen;
    }
};
