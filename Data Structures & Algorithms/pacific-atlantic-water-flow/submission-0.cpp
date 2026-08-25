class Solution {
public:

    void dfs(vector<vector<int>> &heights, int i, int j, vector<vector<int>> &visited, int m, int n){
        visited[i][j] = 1;

        int dr[4] = {1,0,0,-1};
        int dc[4] = {0,-1,1,0};

        for(int x = 0; x<4; x++){
            int nr = dr[x]+i;
            int nc = dc[x]+j;

            if(nr >= 0 && nc >= 0 && nr < m && nc < n && heights[nr][nc] >= heights[i][j] && !visited[nr][nc])
            dfs(heights, nr, nc, visited, m, n);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> soln;

        vector<vector<int>> vstP(m, vector<int>(n, 0));
        vector<vector<int>> vstA(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(i == 0 || j == 0)
                dfs(heights, i, j, vstP, m, n);

                // else if(i == m-1 || j == n-1) WRONG !!!

                if(i == m-1 || j == n-1)
                dfs(heights, i, j, vstA, m, n);
            }
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(vstP[i][j] == 1 && vstA[i][j] == 1)
                soln.push_back({i, j});
            }
        }

        return soln;
    }
};