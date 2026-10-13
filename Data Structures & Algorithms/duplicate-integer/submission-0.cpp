class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int exor = 1;
        for(int i: nums) exor ^= i;
        return exor;
    }
};