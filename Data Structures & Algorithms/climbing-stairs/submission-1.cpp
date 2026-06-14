class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1, prev2=1;
        for(int i = 0; i<n-1; i++){
            int temp = prev1;
            prev1 += prev2;
            prev2 = temp;
        }
        return prev1;
    }
};
