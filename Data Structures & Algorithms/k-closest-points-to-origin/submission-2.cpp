class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,vector<int>>> maxHeap;
        double val;
        for(auto nums: points){
            int x = nums[0];
            int y = nums[1];
            val = ((x*x)+(y*y));
            maxHeap.push({val,nums});
        }

        vector<vector<int>> ans;
        while(maxHeap.size()!=k){
            maxHeap.pop();
        }

        while(!maxHeap.empty()){
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};
