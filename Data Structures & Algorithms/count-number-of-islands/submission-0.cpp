class Solution {
    void DFS(int r, int c, vector<vector<bool>>&vis, vector<vector<char>>& grid, int m, int n){
        if(r<0 || c<0 || r>=m || c>=n || vis[r][c] || grid[r][c]=='0') return;
        vis[r][c] = 1;

        DFS(r+1, c, vis, grid, m, n);
        DFS(r-1, c, vis, grid, m, n);
        DFS(r, c-1, vis, grid, m, n);
        DFS(r, c+1, vis, grid, m, n);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(), n= grid[0].size(), ans = 0;
        vector<vector<bool>>vis(m, vector<bool>(n));

        for(int i=0;i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    DFS(i, j , vis, grid, m, n);
                    ans++;
                }
            }
        }
        return ans;
    }
};
