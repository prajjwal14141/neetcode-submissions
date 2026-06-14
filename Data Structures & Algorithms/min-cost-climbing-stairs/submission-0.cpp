class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>pay(n+1, 0);
        pay[0] = 0; pay[1] = 0;
        for(int i=2; i<=n; i++) pay[i] = min(pay[i-1] + cost[i-1], pay[i-2] + cost[i-2]);
        return pay[n];
    }
};
