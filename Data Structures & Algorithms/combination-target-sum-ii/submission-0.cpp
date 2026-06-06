class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        sort(candidates.begin(),candidates.end());
        backtrack(cur,candidates,target,0);
        return res;
    }

    void backtrack(vector<int> &cur, vector<int>& candidates, int target, int i){
        if(target==0){
            res.push_back(cur);
            return;
        }

        if(target<0 || i>=candidates.size()){
            return;
        }

        cur.push_back(candidates[i]);
        backtrack(cur,candidates,target-candidates[i],i+1);
        cur.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]){
                i++;
        }
        backtrack(cur,candidates,target,i+1);
    }
};
