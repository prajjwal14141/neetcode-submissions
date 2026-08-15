class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>id;
        for(int i=0;i<nums.size();i++) id[nums[i]] = i;
        for(int i=0;i<nums.size();i++)    
            if(id.count(target-nums[i]) && i != id[target-nums[i]]) 
                return {i, id[target-nums[i]]};
        return {};
    }
};
