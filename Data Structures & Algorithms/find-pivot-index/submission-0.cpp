class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int  ps = 0, t = accumulate(nums.begin(), nums.end(), 0);
        for(int i=0; i<nums.size(); i++){
            if(ps + nums[i] == t - ps) return i;
            ps += nums[i];
        }
        return -1;
    }
};