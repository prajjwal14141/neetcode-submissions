class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), dr[] = {0, 0, -1, 1}, dc[] = {-1, 1, 0, 0};
        queue<pair<int, int>>q;
        //cols
        for(int i=0; i<m; i++){
            if(grid[i][0] == 1) q.push({i, 0});
            if(grid[i][n-1]==1) q.push({i, n-1});
        }
        //rows
        for(int j=0; j<n; j++){
            if(grid[0][j] == 1) q.push({0, j});
            if(grid[m-1][j]==1) q.push({m-1, j});
        }

        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            grid[r][c] = 0;
            q.pop();

            for(int i=0; i<4; i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 &&nr<m && nc>=0 && nc<n && grid[nr][nc] == 1)   q.push({nr, nc});
            }
        }

        for(auto v: grid)
            for(int i: v)
                if(i==1) ans++;

        return ans;
    }
};