class Solution {
public:
    vector<vector<int>> memo;
    int change(int amount, vector<int>& coins) {
        int m = coins.size();
        memo.resize(m, vector<int>(amount+1, -1));
        return dfs(amount, m-1, coins);
    }

    int dfs(int amount, int i, vector<int>& coins){
        if(i<0 || amount<0){
            return 0;
        }

        if(amount == 0){
            return 1;
        }

        if(memo[i][amount]!=-1){
            return memo[i][amount];
        }
        
        int take = 0;
        
        if(coins[i]<=amount){
            take = dfs(amount - coins[i],i,coins);
        }
        int no_take = dfs(amount, i-1, coins);

        memo[i][amount] = take + no_take;

        return memo[i][amount];
    }
};
