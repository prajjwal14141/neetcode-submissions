class Solution {
public:
    int reverse(int x) {
        long long rev = 0, temp = abs(1LL*x);
        while(temp > 0){
            int d = temp % 10;
            rev = rev*10 + d;
            temp /= 10;
        }
        if (rev > INT_MAX) return 0;
        return (x > 0) ? rev : -1 * rev;
    }
};