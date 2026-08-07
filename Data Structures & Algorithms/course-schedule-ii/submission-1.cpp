class Solution {
    bool cycle(vector<bool>&vis,vector<bool>&pvis,vector<vector<int>>&adj,int s,vector<int>&ans){
        vis[s] = 1; pvis[s] = 1;
        
        for(int n: adj[s]){
            if(pvis[n]) return 1;
            else if(!vis[n]) if(cycle(vis, pvis, adj, n, ans)) return 1; 
        }
        pvis[s] = 0;
        ans.push_back(s);
        return 0;
    }
public:
    vector<int> findOrder(int num, vector<vector<int>>& prq) {
        vector<vector<int>>adj(num);
        vector<int>ans;
        for(vector v: prq) adj[v[1]].push_back(v[0]);
        vector<bool>vis(num), pvis(num);
        for(int i=0;i<num;i++) if(!vis[i])  if(cycle(vis,pvis,adj,i,ans)) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
