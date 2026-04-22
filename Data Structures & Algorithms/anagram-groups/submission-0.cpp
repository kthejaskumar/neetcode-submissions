class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> m;
        for(int i=0;i<strs.size();i++){
            string key = strs[i];
            sort(key.begin(),key.end());
            if(m.find(key)!=m.end()){
                int location = m[key];
                ans[location].push_back(strs[i]);
            }
            else{
                int location = ans.size();
                m[key] = location;
                ans.push_back({strs[i]});
            }
        }
        return ans;
    }
};
