class Solution {
public:
    string longestPalindrome(string s) {
        int r,l;
        int resIdx, resLen=0;
        for(int i=0;i<s.length();i++){
            l = i;
            r = i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    resLen = r-l+1;
                    resIdx = l;
                }
                r++;
                l--;
            }
            

            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                if(r-l+1>resLen){
                    resLen = r-l+1;
                    resIdx = l;
                }
                r++;
                l--;
            }
            
        }
        return s.substr(resIdx,resLen);
    }
};
