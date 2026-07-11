class Solution {
    void DFS(vector<vector<char>>& board, int r, int c, int m, int n, vector<vector<bool>>&check){
        if(r<0 || r>=m || c<0 || c>=n || board[r][c] == 'X' || check[r][c]) return;
        check[r][c] = 1;

        DFS(board, r+1, c, m, n, check);
        DFS(board, r-1, c, m, n, check);
        DFS(board, r, c+1, m, n, check);
        DFS(board, r, c-1, m, n, check);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>>check(m, vector<bool>(n));
        for(int j=0;j<n;j++){
            if(board[0][j] == 'O'){
                DFS(board, 0, j, m, n, check);
                check[0][j] = 1;
            }
            if(board[m-1][j] == 'O'){
                DFS(board, m-1, j, m, n, check);
                check[m-1][j] = 1;
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                DFS(board, i, 0, m, n, check);
                check[i][0] = 1;
            }
            if(board[i][n-1] == 'O'){
                DFS(board, i, n-1, m, n, check);
                check[i][n-1] = 1;
            }
        }

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(!check[i][j]) board[i][j] = 'X';
    }
};
