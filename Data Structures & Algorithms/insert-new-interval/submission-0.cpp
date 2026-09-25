class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(auto nums : intervals){
            int start = nums[0];
            int end = nums[1];
            int lastend = ans.back()[1];

            if(start<=lastend){
                ans.back()[1] = max(end,lastend);
            }else{
                ans.push_back(nums);
            }
        }
        return ans;
    }
};
