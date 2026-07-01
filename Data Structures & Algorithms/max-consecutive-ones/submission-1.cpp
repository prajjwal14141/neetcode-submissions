class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i=0, ans=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j] == 1) ans = max(ans, j-i+1);
            else i=j+1;
        }
        return ans;
    }
};