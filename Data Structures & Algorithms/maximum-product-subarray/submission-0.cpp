class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans =  nums[0], mx = ans, mn = mx;
        for(int i=1; i< nums.size(); i++){
            if(nums[i] < 0) swap (mx, mn);
            mx = max(nums[i], nums[i]*mx);
            mn = min(nums[i], mn*nums[i]);
            ans = max(ans, mx);
        }
        return ans;
    }
};
