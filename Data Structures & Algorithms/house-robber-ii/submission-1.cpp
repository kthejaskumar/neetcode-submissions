class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return nums[0];
        return max(helper(vector<int>(nums.begin()+1,nums.end())),helper(vector<int>(nums.begin(),nums.end()-1)));
    }

    int helper(vector<int> numbers){
        int n = numbers.size();
        if(n<=1) return numbers[0];
        vector<int> dp(n,0);
        dp[0] = numbers[0];
        dp[1] = max(numbers[0],numbers[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],numbers[i]+dp[i-2]);
        }
        return dp[n-1];
    }
};
