class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=1;i<flowerbed.size();i++){
            if(flowerbed[i] == 0 && flowerbed[i-1] != 1){
                n--;
                i++;
            }
            if(n<=0) return 1;
        }
        return 0;
    }
};