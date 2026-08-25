class Solution {
public:

    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &visited, int &crntArea, int n, int m){
        // int crntArea = 0;
        visited[i][j] = 1;
        int dr[4] = {0, 0, 1, -1};
        int dc[4] = {1, -1, 0, 0};

        for(int x = 0; x<4; x++){
            int nr = dr[x]+i;
            int nc = dc[x]+j;

            if(nr >= 0 && nc >=0 && nr < n && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]){
                crntArea++;
                dfs(grid, nr, nc, visited, crntArea, n, m);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxA = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int crntArea = 1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    dfs(grid, i, j, visited, crntArea, n, m);
                    maxA = max(maxA, crntArea);
                    crntArea = 1;
                }
            }
        }

        return maxA;
    }
};