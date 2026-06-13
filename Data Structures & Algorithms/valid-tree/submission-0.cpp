class Solution {
public:
     void BFS(vector<vector<int>>&adj, vector<bool>&vis, int s){
        
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

    bool connected(vector<vector<int>>& edges, int n){
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;
        vector<bool>vis(n);
        for(int i=0;i<adj.size();i++) {
            if(!vis[i]) BFS(adj, vis, i), ans++;
            if(ans > 1) return 0;
        }
        return 1;
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        return connected(edges, n) && (edges.size() == n-1);
    }
};
