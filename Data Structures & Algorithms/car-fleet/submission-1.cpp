class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> ps;
        for(int i=0;i<position.size();i++){
            ps.push_back(make_pair(position[i],speed[i]));
        }

        sort(ps.rbegin(),ps.rend());
        
        stack<double> time;

        for(auto pos : ps){
            double t1 = (double)(target-pos.first)/pos.second;
            if(time.empty() || t1>time.top()){
                time.push(t1);
            }
        }

        return time.size();
    }
};
