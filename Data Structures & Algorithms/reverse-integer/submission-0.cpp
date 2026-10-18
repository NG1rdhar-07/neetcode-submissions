class Solution {
public:
    int reverse(int x) {
        long long temp = abs((long long)x);
        long long ans = 0;
        bool isP = true;

        if(x < 0)
        isP = false;

        while(temp > 0){
            int lD = temp % 10;
            ans = ans * 10 + lD;
            temp /= 10;
        }

        if(!isP)
        ans = -ans;

        if(ans < INT_MIN || ans > INT_MAX)
        return 0;

        return ans;
    }
};
