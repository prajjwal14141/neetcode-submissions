class Solution {
    void BFS(vector<vector<int>>& isConnected, int s, int n, vector<bool>&vis){
        queue<int>q;
        q.push(s);
        vis[s] = 1;

        while(!q.empty()){
            int f = q.front();
            q.pop();

            for(int i=0;i<n;i++){
                if(!vis[i] && isConnected[f][i] == 1){
                    q.push(i);
                    vis[i] = 1;
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vector<bool>vis(n);
        for(int i=0;i<n;i++) if(!vis[i]) BFS(isConnected, i, n, vis), ans++;
        return ans;
    }
};