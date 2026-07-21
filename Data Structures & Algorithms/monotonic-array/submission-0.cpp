class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() <=1) return 1;
        if(nums[1] >= nums[0]) {
             for(int i=1; i<nums.size(); i++) if(nums[i] < nums[i-1]) return 0;
        }
        else for(int i=1; i<nums.size(); i++) if(nums[i] > nums[i-1]) return 0;
        return 1;
    }
};