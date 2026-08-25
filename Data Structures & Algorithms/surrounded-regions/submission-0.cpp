class Solution {
public:

    void dfs(vector<vector<char>> &board, int i, int j, vector<vector<int>> &visited, int m, int n){
        visited[i][j] = 1;

        int dr[4] = {1,0,0,-1};
        int dc[4] = {0,-1,1,0};

        for(int x = 0; x<4; x++){
            int nr = dr[x]+i;
            int nc = dc[x]+j;

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && board[nr][nc] == 'O' && !visited[nr][nc])
            dfs(board, nr, nc, visited, m, n);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O')
                dfs(board, i, j, visited, m, n);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j])
                board[i][j] = 'X';
            }
        }

    }
};
