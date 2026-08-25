class Solution {
public:

    // void bfs(vector<vector<int>>& grid, vector<vector<int>> rotten, int crntOrange, int r, int c, int t){
    //     queue<pair<pair<int, int>, int>> q;
    //     q.push({{r, c}, t});

        
    // }

    int orangesRotting(vector<vector<int>>& grid) {
        int minT = 0;
        
        //int rottenInitially = 0;
        int freshInitally = 0;
        int extraRot = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<int>> rotten(n, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1)
                freshInitally++;

                else if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    //rottenInitially++;
                }
            }
        }

        while(!q.empty()){
            auto[c, t] = q.front();
            q.pop();
            minT = max(minT, t);

            for(int j = 0; j<4; j++){
                int nR = c.first + dr[j];
                int nC = c.second + dc[j];

                if(nR >= 0 && nR < n && nC >= 0 && nC < m && grid[nR][nC] == 1)
                {
                    q.push({{nR, nC}, t+1});
                    grid[nR][nC] = 2;
                    extraRot++;
                }
            }
        }   

        if(extraRot != freshInitally)
        return -1;

        return minT;
    }
};
