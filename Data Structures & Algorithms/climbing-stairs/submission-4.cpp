class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
       vector<int>track(n+1);
        track[1] = 1;
        track [2] = 2;
        for(int i = 3; i<=n; i++) track[i] = track[i-1] + track[i-2];
        return track[n];
    }
};
