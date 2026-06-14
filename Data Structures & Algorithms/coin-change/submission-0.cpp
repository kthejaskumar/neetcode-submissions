class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int res=  dfs(coins,amount,coins.size()-1);
        return res>=1e9?-1:res;
    }

    int dfs(vector<int>& coins, int amount, int i){
        if(amount == 0){
            return 0;
        }

        if(i<0){
            return 1e9;
        }

        if(amount<0){
            return 1e9;
        }

        int inc = 1 + dfs(coins,amount-coins[i],i);
        int exl = dfs(coins,amount,i-1);
        int ans = min(inc,exl); 
        return ans;
    }
};
