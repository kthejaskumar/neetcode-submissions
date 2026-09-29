class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> zeros;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    zeros.push_back(make_pair(i,j));
                }
            }
        }

        for(auto nums : zeros){
            int row = nums.first;
            int col = nums.second;

            for(int i=0;i<matrix[0].size();i++){
                matrix[row][i] = 0;
            }

            for(int i=0;i<matrix.size();i++){
                matrix[i][col] = 0;
            }
        }
    }
};
