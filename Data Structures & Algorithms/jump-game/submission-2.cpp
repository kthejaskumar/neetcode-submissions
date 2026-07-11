class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums,0,n);
    }

    bool dfs(vector<int>& nums, int i,int n){
        if(i == n-1){
            return true;
        }

        int end = min(n-1,i+nums[i]);
        for(int j=i+1;j<=end;j++){
            if(dfs(nums,j,n)){
                return true;
            }
        }
        return false;
    }
};
