class Solution {
public:
    bool helper(vector<vector<char>>& board,int i,int j,char c){
        for(int k=0;k<9;k++){
            if(board[i][k]==c) return false;
            if(board[k][j]==c) return false;
        }

        int m = (i/3)*3;
        int n = (j/3)*3;
        for(int h=0;h<3;h++){
            for(int f=0;f<3;f++){
                if(board[h+m][f+n]==c)return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.') continue;
                char c = board[i][j];
                board[i][j]='.';
                if(!helper(board,i,j,c)){
                    return false;
                }
                board[i][j]=c;
            }
        }
        return true;
    }


};
