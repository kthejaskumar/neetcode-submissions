class Solution {
public:
    vector<vector<int>> memo;
    int totalSum = 0;
    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(),0);
        memo.resize(nums.size(), vector<int>(2*totalSum+1,INT_MIN));
        return dfs(nums,target,0,0,totalSum);
    }

    int dfs(vector<int>& nums, int target, int i, int sum, int totalSum){
        if(i==nums.size()){
            return sum==target;
        }

        if(memo[i][sum+totalSum]!=INT_MIN){
            return memo[i][sum+totalSum];
        }

        memo[i][sum+totalSum] = dfs(nums,target,i+1,sum+nums[i],totalSum) + dfs(nums,target,i+1,sum-nums[i],totalSum);
        return memo[i][sum+totalSum];
    }
};
