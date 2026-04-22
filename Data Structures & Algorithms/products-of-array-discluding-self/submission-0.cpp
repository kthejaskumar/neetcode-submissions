class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out(nums.size(),1);
        int left=1;
        for(int i=0;i<nums.size();i++){
            out[i]*=left;
            left*=nums[i];
        }
        int right=1;
        for(int i=nums.size()-1;i>=0;i--){
            out[i]*=right;
            right*=nums[i];
        }
        return out;
    }
};
