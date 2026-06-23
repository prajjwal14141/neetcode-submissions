#include<bits/stdc++.h>
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        size_t minlen = INT_MAX;
        string ans = "", cmp;
        for(string s: strs) {
            if(minlen > s.length()) {cmp = s; minlen = s.length();}
        }
        for(int i = 0; i<minlen; i++){
            for(int j = 0; j<strs.size(); j++){
                if(strs[j][i] != cmp[i]) return ans;
            }
            ans += cmp[i];
        }
        return ans;
    }
};