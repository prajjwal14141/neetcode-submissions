class Solution {
    void backtrack(vector<int>& nums, int s, int t, vector<int>&curr, vector<vector<int>>&ans){
        if(t == 0){
            ans.push_back(curr);
            return;
        }
        else if(t<0) return;
      
        for(int i=s;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(nums, i, t-nums[i], curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        backtrack(nums, 0, target, curr, ans);
        return ans;
    }
};
