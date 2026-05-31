class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        sum(nums,target,cur,0);
        return res;
    }

    void sum(vector<int>& nums, int target, vector<int> &cur,int i){
        if(target==0){
            res.push_back(cur);
            return;
        }

        if(target<0 || i>=nums.size()){
            return;
        }

        cur.push_back(nums[i]);
        sum(nums,target-nums[i],cur,i);
        cur.pop_back();
        sum(nums,target,cur,i+1);
    }
};
