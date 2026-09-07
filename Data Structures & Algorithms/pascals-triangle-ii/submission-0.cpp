class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>dp;
        dp.push_back({1});

        for(int i=1;i<=rowIndex;i++){
            vector<int>curr(i+1);
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) curr[j] = 1;
                else curr[j] = dp[i-1][j-1] + dp[i-1][j];
            }
            dp.push_back(curr);
        }
        return dp[rowIndex];
    }
};