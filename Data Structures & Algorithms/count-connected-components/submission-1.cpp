class Solution {
public:
    void BFS(vector<vector<int>>adj, vector<bool>&vis, int s){
        queue<int>q;
        q.push(s);
        vis[s] = 1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int i: adj[curr]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        vector<bool>vis(n);
        for(int i=0;i<adj.size();i++) if(!vis[i]) BFS(adj, vis, i), ans++;
        return ans;
    }
};
