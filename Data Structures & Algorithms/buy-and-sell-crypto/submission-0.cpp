class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPrft = 0;
        int minPrc = prices[0];
        
        for(int i = 1; i<prices.size(); i++){
            maxPrft = max(maxPrft, prices[i]-minPrc);
            minPrc = min(minPrc, prices[i]);
        }

        return maxPrft;
    }
};
