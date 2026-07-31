class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>frq;
        for(char c: ransomNote) frq[c]++;
        for(char c: magazine) if(frq.count(c))    frq[c]--;
        for(auto it: frq){
            if(it.second > 0)   return 0;
        }
        return 1;
    }
};