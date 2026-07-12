class Solution {
    void DFS(int i, vector<bool>&vis, vector<vector<int>>& mat){
        vis[i] = 1;
        for(int j=0;j<mat[0].size();j++)    if(mat[i][j] == 1 && !vis[j]) DFS(j, vis, mat);
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        int ans = 0;
        vector<bool>vis(mat.size());
        for(int i=0; i<mat.size();i++){
                if(!vis[i]){
                    DFS(i, vis, mat);
                    ans++;
                }
        }
        return ans;
    }
};