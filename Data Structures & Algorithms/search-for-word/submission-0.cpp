class Solution {
public:
    int ROWS;
    int COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for(int r=0;r<ROWS;r++){
            for(int c=0;c<COLS;c++){
                if(backtrack(r,c,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(int r, int c, vector<vector<char>>& board, string word, int i){
        if(i==word.size()){
            return true;
        }

        if(r<0 || c<0 || r>=ROWS || c>=COLS || board[r][c] == '#' || board[r][c]!=word[i]){
            return false;
        }
        board[r][c] = '#';
        bool res = backtrack(r+1,c,board,word,i+1) || 
                    backtrack(r-1,c,board,word,i+1) ||
                    backtrack(r,c+1,board,word,i+1) ||
                    backtrack(r,c-1,board,word,i+1);
        board[r][c] = word[i];
        return res;
    }
};
