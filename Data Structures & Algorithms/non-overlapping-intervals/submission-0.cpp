class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int lastend = intervals[0][1];
        int cnt = 0;
        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start<lastend){
                cnt++;
                lastend = min(lastend,end);
            }
            else{
                lastend = intervals[i][1];
            }
        }
        return cnt;
    }
};
