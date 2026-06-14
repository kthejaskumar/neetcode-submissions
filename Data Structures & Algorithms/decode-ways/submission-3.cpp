class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return dfs(s,0,dp);
    }

    int dfs(string s, int i, vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

        int res = dfs(s,i+1,dp);

        if(i<s.size()-1){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<'7')){
                res+=dfs(s,i+2,dp);
            }
        }

        return dp[i] = res;
    }
};
