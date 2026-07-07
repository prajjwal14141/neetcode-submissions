class Solution {
    bool DFS(vector<bool>&vis, vector<bool>&pvis, vector<vector<int>>&adj, int s){
        vis[s] = 1, pvis[s] = 1;

        for(int i: adj[s]){
            if(!vis[i]) {if(DFS(vis, pvis, adj, i)) return 1;}
            else if(pvis[i]) return 1;
        } 
        pvis[s] = 0;
        return 0;
    }
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>>adj(n);
        for(vector<int>v: p) adj[v[1]].push_back(v[0]);

        vector<bool>vis(n), pvis(n);

        for(int i=0;i<n;i++)
            if(!vis[i])
                if(DFS(vis, pvis, adj, i)) return 0;
        return 1;
    }
};
