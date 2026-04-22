class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(),0);
        stack<pair<int,int>> st;
        for(int i=0;i<temperatures.size();i++){
            int temp = temperatures[i];
            while(!st.empty() && temp>st.top().first){
                auto pair = st.top();
                st.pop();
                result[pair.second] = i - pair.second;
            }
            st.push({temp,i});
        }
        return result;
    }
};
