class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0, dr[] = {1,-1,0,0}, dc[] = {0,0,1,-1};
        vector<vector<bool>>vis(m, vector<bool>(n));

        //{{r, c}, tm}
        queue<pair<pair<int, int>, int>>q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        
        while(!q.empty()){
            int r = q.front().first.first, c = q.front().first.second, t = q.front().second;
            q.pop();

            ans = max(ans, t);

            for(int i=0;i<4;i++){
                int nr = r + dr[i], nc = c + dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] == 1){
                    q.push({{nr, nc}, t+1});
                    vis[nr][nc] = 1;
                }
            }
        }
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                    if(!vis[i][j] && grid[i][j] == 1)   return -1;
        return ans;
    }
};
