class Solution {
    bool cycle(vector<bool>&vis, vector<bool>&pvis,  vector<vector<int>>&adj, int s){
        vis[s] = 1; pvis[s] = 1;
        for(int n: adj[s]){
            if(pvis[n]) return 1;
            else if(!vis[n]) if(cycle(vis, pvis, adj, n)) return 1; 
        }
        pvis[s] = 0;
        return 0;
    }
public:
    bool canFinish(int num, vector<vector<int>>& prq) {
        vector<vector<int>>adj(num);
        for(vector v: prq) adj[v[1]].push_back(v[0]);
        vector<bool>vis(num), pvis(num);
        for(int i=0;i<num;i++) if(!vis[i])  if(cycle(vis,pvis,adj,i)) return 0;
        return 1;
    }
};
