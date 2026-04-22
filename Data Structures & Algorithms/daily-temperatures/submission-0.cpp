class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        for(int i=0;i<temperatures.size();i++){
            int curr = temperatures[i];
            int cnt=0;
            int ans=-1;
            for(int j=i+1;j<temperatures.size();j++){
                int maxtemp = temperatures[j];
                if(maxtemp>curr){
                    cnt++;
                    ans=cnt;
                    break;
                }
                else{
                    cnt++;
                }
            }
            if(ans!=-1){
                result.push_back(cnt);
            }
            else{
                result.push_back(0);
            }
        }
        return result;
    }
};
