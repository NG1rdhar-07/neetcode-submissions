class Solution {
public:

    bool helper(vector<vector<char>>& board, int index, string word, int i, int j, int m, int n, vector<vector<int>> &visited){
        if(index == word.length())
        return true;

        if(i >= m || i< 0 || j >= n || j < 0)
        return false;

        if(board[i][j] != word[index])
        return false;

        if(visited[i][j])
        return false;

        visited[i][j] = 1;


//forgot this !!!
        bool found = (helper(board, index+1, word, i-1, j, m, n, visited) ||
        helper(board, index+1, word, i, j-1, m, n, visited) ||
        helper(board, index+1, word, i, j+1, m, n, visited) ||
        helper(board, index+1, word, i+1, j, m, n, visited));

        visited[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vst(m, vector<int>(n, 0));

        // return helper(board, 0, word, 0, 0, m, n, vst);
    
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(helper(board, 0, word, i, j, m, n, vst))
                return true;
            }
        }

        return false;
    }
};
