class Solution {
public:

    void bfs(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y, int n, int m){
        int dr[4] = {1, 0, 0, -1};
        int dc[4] = {0, -1, 1, 0};

        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = 1;

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first;
            int c = node.second;

            for(int i = 0; i<4; i++){
                int nR = r + dr[i];
                int nC = c + dc[i];

                if(nR >= 0 && nC >= 0 && nR < n && nC < m && grid[nR][nC] == '1' && !visited[nR][nC])
                {
                    q.push({nR, nC});
                    visited[nR][nC] = 1;    
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int noOfIslands = 0;
        

        queue<pair<int, int>> q; //
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    bfs(grid, visited, i, j, n, m);
                    noOfIslands++;
                }
            }
        }

        return noOfIslands;
    }
};
