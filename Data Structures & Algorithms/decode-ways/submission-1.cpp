class Solution {
public:
    int numDecodings(string s) {
        int prev2 = 1, prev1 = (s[0] != '0');
        for(int i=2;i<=s.length();i++){
            int curr = 0, val = (s[i-2]-'0') * 10 + s[i-1]-'0';
            if(s[i-1] != '0') curr = prev1;
            if(val >= 10 && val <=26) curr += prev2;

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
