class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxsofar=-1;
        int left=0,right=heights.size()-1;
        while(left<right){
            int leftval = heights[left];
            int rightval = heights[right];
            int minval = min(leftval,rightval);
            int val = minval*(right-left);
            maxsofar = max(val,maxsofar);
            if(leftval<rightval){
                left++;
            }
            else{
                right--;
            }
        }
        return maxsofar;
    }
};
