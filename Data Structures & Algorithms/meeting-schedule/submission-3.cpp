/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool compare(Interval x, Interval y){
        return x.start < y.start;
    }
   
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(), compare);
        for(int i=1;i<intervals.size();i++){
            int lastend = intervals[i-1].end;
            int start = intervals[i].start;

            if(lastend>start){
                return false;
            }

        }

        return true;
    }
};
