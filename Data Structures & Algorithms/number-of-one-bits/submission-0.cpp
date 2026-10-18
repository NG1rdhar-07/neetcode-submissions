class Solution {
public:
    int hammingWeight(uint32_t n) {
        int x = n;
        int c = 0;

        while(x > 0){
            x = x&(x-1);
            c++;
        }

        return c;
    }
};
