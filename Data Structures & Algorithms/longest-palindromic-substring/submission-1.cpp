class Solution {
    int isPalin(string&a, int s, int e){
        while(s>=0 && e<a.length() && a[s] == a[e]) s--,e++;
        return e-s-1;
    }
public:
    string longestPalindrome(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            int len = max(isPalin(s, i, i), isPalin(s, i, i+1));
            if(len > ans.length()) ans = s.substr(i - (len-1)/2, len); 
        }
        return ans;
    }
};