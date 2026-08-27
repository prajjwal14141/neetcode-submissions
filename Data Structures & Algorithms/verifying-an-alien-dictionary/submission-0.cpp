class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int>rank;
        for(int i=0;i<order.length();i++) rank[order[i]] = i;
        for(int i=0;i<words.size()-1;i++){
            bool same = 1;
            for(int j=0;j<min(words[i].length(), words[i+1].length()); j++){
                if(rank[words[i][j]] > rank[words[i+1][j]]) return 0;
                else if(rank[words[i][j]] < rank[words[i+1][j]]){
                    same = 0;
                    break;
                }
            }
            if(same && words[i].length() > words[i+1] .length()) return 0;
        }
        return 1;
    }
};