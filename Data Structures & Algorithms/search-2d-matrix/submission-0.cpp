class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0,bot=matrix.size()-1;
        int row=-1;
        while(top<=bot){
            int mid = (top+bot)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1]){
                row=mid;
                break;
            }
            else if(matrix[mid][matrix[0].size()-1]<target){
                top=mid+1;
            }
            else{
                bot=mid-1;
            }
        }
        if(row==-1)return false;

        int left=0, right=matrix[row].size()-1;
        while(left<=right){
            int mid= (left+right)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};
