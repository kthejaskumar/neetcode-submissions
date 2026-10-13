class Solution {
public:
    vector<vector<int>> memo;
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        memo.resize(m,vector<int>(n,-1));
        return dfs(0,0,text1,text2);
    }

    int dfs(int i, int j, string text1, string text2){
        if(i==text1.size() || j==text2.size()){
            return 0;
        }

        if(text1[i]==text2[j]){
            return 1 + dfs(i+1,j+1,text1,text2);
        }

        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        memo[i][j] = max(dfs(i+1,j,text1,text2), dfs(i,j+1,text1,text2));
        return memo[i][j];
    }
};
