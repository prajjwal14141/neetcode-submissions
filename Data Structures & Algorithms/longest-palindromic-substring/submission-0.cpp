class Solution {
    bool ispalindrome(string& a, int s, int e){
        while(s<=e){
            if(a[s] != a[e]) return 0;
            s++, e--;
        }
        return 1;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.length();i++){
            for(int j=i; j<s.length();j++){
                if(ispalindrome(s,i,j) && s.substr(i, j-i+1).length() > ans.length())
                    ans = s.substr(i, j-i+1);
            }  
        }
        return ans; 
    }
};