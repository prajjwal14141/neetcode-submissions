class Solution {
    void LCS(vector<vector<int>>&dp, string s1, string s2, int m, int n){
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)
                (s1[i-1] == s2[j-1]) ? dp[i][j] = 1 + dp[i-1][j-1] : dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int m = str1.length(), n = str2.length();
        if(m == 0) return str2;
        if(n == 0) return str1;

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        LCS(dp, str1, str2, m, n);
        int i = m, j = n;

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                ans += str2[j-1];
                i--, j--;
            }
            else if(dp[i-1][j] >= dp[i][j-1]){
                ans += str1[i-1];
                i--;
            }
            else{
                ans += str2[j-1];
                j--;
            }
        }

        //add rem values
        while(i>0){
            ans += str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};