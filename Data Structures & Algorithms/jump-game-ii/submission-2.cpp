class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        unordered_map<int,int> memo;
        return dfs(nums,0,n,memo);
    }

    int dfs(vector<int>& nums, int i, int n, unordered_map<int,int> &memo){
        if(memo.count(i)){
            return memo[i];
        }
        if(i==n){
            return 0;
        }

        if(nums[i]==0){
            return 1e9;
        }

        int res = 1e9;
        int end = min(n, i+nums[i]);
        for(int j=i+1;j<=end;j++){
            res = min(res, 1+ dfs(nums,j,n,memo));
        }
        memo[i] = res;
        return res;
    }
};
