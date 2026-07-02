class Solution {
    void dfs(vector<vector<int>>& image, int r, int c, int clr, int ini){
        if(r<0 || r>=image.size() || c<0 || c>=image[0].size() || image[r][c]!=ini )  return;
        image[r][c] = clr;
        dfs( image, r+1,c, clr, ini);
        dfs(image, r-1,c, clr, ini);
        dfs(image, r,c+1, clr, ini);
        dfs(image, r,c-1, clr, ini);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini = image[sr][sc];
        if(ini == color) return image;
        dfs( image, sr, sc, color, ini);
        return image;
    }
};