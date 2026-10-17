class Solution {
public:
    vector<vector<int>> memo;
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.length();
        int n=s2.length();
        memo.resize(m+1, vector<int>(n+1,-1));
        return dfs(s1,s2,s3,0,0,0);
    }

    bool dfs(string s1, string s2, string s3,int i, int j, int k){
        if(k==s3.length()){
            return (i==s1.length()) && (j==s2.length());
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        bool res = false;
        if(i<s1.length() && s1[i]==s3[k]){
            res = dfs(s1,s2,s3,i+1,j,k+1);
        }

        if(!res && j<s2.length() && s2[j]==s3[k]){
            res = dfs(s1,s2,s3,i,j+1,k+1);
        }
        memo[i][j] = res;
        return res;
    }
};
