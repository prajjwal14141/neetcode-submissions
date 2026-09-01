class Solution {
    void backtrack(vector<int>c, int t, vector<int>&curr, vector<vector<int>>&ans, int s){
        if(t == 0){
            ans.push_back(curr);
            return;
        }
        else if(t < 0) return;

        for(int i=s; i<c.size(); i++){
            curr.push_back(c[i]);
            backtrack(c, t-c[i], curr, ans, i);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        backtrack(candidates, target, curr, ans, 0);
        return ans;
    }
};