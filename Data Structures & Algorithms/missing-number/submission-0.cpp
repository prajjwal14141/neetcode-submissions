class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i: nums) sum+=i;
        return ((double)(n)/2.0)*(n+1) - sum;
    }
};
