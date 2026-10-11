class Solution {
public:
    vector<vector<int>> memo;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int n : nums){
            sum+=n;
        }

        if(sum%2){
            return false;
        }

        memo.resize(nums.size(), vector<int>(sum/2+1, -1));

        return dfs(0,nums,sum/2);
    }

    bool dfs(int i, vector<int>& nums, int target){
        if(i==nums.size()){
            return target == 0;
        }

        if(target<0){
            return false;
        }

        if(memo[i][target]!=-1){
            return memo[i][target];
        }

        memo[i][target] = dfs(i+1,nums,target) || dfs(i+1,nums,target-nums[i]);
        return memo[i][target];
    }
};
