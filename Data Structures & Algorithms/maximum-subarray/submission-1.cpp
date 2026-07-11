class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int sum=0;
        for(int num : nums){
            if(sum<0) sum=0;
            sum+=num;
            res = max(res,sum);
        }
        return res;
        
    }
};
