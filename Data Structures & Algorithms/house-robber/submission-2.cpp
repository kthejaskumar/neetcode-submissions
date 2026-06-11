class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums[0];
        vector<int> dp(n,-1);

        return dfs(nums,dp,0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0],nums[1]);
        // for(int i=2;i<n;i++){
        //     dp[i] = max(dp[i-1],nums[i]+dp[i-2]);
        // }
        // return dp[n-1];
    }

    int dfs(vector<int>& nums,vector<int>& dp, int i){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int inc = 0, exl = 0;
        inc = nums[i] + dfs(nums,dp,i+2);
        exl = dfs(nums,dp,i+1);
        dp[i] = max(inc,exl);
        return dp[i];
    }
};
