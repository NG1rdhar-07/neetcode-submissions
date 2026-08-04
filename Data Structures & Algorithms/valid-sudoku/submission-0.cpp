class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            for(int j = 0; j< 9; j++){
                if(board[i][j] != '.'){
                    int sRow = (i/3)*3;
                    int sCol = (j/3)*3;

                    for(int k = sRow; k<sRow+3; k++){
                        for(int l = sCol; l<sCol+3; l++){
                            if(i != k && j != l && board[i][j] == board[k][l])
                            return false;
                        }
                    }

                    for(int k = 0; k<9; k++){
                        if(k != j && board[i][j] == board[i][k])
                        return false;
                        
                        if(k != i && board[i][j] == board[k][j])
                        return false; 
                    }
                }
            }
        }

        return true;
    }
};
