class Solution {
    //method- fix a value, have 2 sum problem ahead. Sorting helps to avoid duplicates
    //Steps- 1. Sort and traverse
    //       2. solve as 2 sum now.
public:
    vector<vector<int>> twoSum(vector<int>nums, int val, int s){
        vector<vector<int>>temp;
        int e=nums.size()-1;
            while(s<e){
                if(nums[s] + nums[e] > val) e--;
                else if(nums[s] + nums[e] < val) s++;
                else {
                    temp.push_back({nums[s],nums[e]});
                    while(s < e && nums[s] == nums[s + 1]) s++;
                    while(s < e && nums[e] == nums[e - 1]) e--;
                    s++;
                    e--;
                }
            }
        return temp;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> rem = twoSum(nums,-nums[i],i+1);
            if(!rem.empty()) for(auto &p : rem)   ans.push_back({nums[i], p[0], p[1]});
        }
        return ans;
    }
};