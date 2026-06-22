class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans , frq=0;
        for(int i:nums){
            if(frq==0) ans = i;
            if(ans==i) frq++;
            else frq--;
        }
        return ans;
    }
};