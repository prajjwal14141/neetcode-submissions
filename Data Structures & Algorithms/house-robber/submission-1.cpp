class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        
        for(int i=2; i<nums.size(); i++){
            int rob = max(prev2+nums[i], prev1);
            prev2 = prev1;
            prev1 = rob;
        }
        return prev1;
    }
};