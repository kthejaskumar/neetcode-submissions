class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left(height.size());
        vector<int> right(height.size());
        int maxsofar=0;
        for(int i=0;i<height.size();i++){
            maxsofar = max(maxsofar,height[i]);
            left[i]=maxsofar;
        }
        maxsofar=0;
        for(int i=height.size()-1;i>=0;i--){
            maxsofar = max(maxsofar,height[i]);
            right[i]=maxsofar;
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            int waterlevel = min(left[i],right[i]);
            ans+=max(0,waterlevel-height[i]);
        }
        return ans;
    }
};
