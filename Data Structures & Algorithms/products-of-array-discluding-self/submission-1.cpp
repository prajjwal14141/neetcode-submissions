class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>p(nums.size(), 1), s(nums.size(), 1);
        int prod = nums[0];
        for(int i=1;i<nums.size();i++)  p[i] = prod, prod *= nums[i];
        prod = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--) s[i] = prod, prod *= nums[i];
        for(int i=0;i<nums.size();i++) p[i] *= s[i];
        return p;
    }
};
