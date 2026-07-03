class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 0, prev1 = 1;
        for(int i = 1;i<n;i++){
            int temp = prev1+1;
            prev2=prev1;
            prev1=temp;
        }
        return prev1;
    }
};
