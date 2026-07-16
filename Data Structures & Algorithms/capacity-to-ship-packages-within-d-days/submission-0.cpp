class Solution {
    bool possible(vector<int>&nums, int days, int w){
        int sum = 0, d = 1;
        for(int i: nums){
            if(sum + i <= w) sum += i;
            else d++, sum = i;
        }
        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& nums, int days) {
        int s = 0, e = accumulate(nums.begin(), nums.end(), 0), ans = 0;
        for(int i: nums) s = max(s, i);

        while(s<=e){
            int mid = (s+e)/2;
            if(possible(nums, days, mid)){
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};