class Solution {
public:
    int countSubstrings(string s) {
        int r,l;
        int res=0;
        for(int i=0;i<s.length();i++){
            l = i;
            r = i;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                res++;
                r++;
                l--;
            }
            

            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l]==s[r]){
                res++;
                r++;
                l--;
            }
            
        }
        return res;
    }
};
