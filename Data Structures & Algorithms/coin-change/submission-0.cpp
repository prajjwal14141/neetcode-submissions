class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int sum = 0, ans = 0;
        for(int i=coins.size()-1;i>=0;i--){
            if(sum == amount) return ans;
            if(coins[i] <= amount) {
                int n =  amount / coins[i];
                amount %= coins[i];
                ans += n;
                sum = sum + coins[i] * n;
            } 
        }
        return (amount==0) ? ans : -1;
    }
};
