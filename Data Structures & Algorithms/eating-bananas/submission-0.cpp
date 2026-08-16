class Solution {
   public:
    int netTimeTaken(vector<int>& piles, int rate) {
        int tt = 0;
        for (int it : piles) 
        // tt += (it / rate); // did mistake here
        // tt += (it + rate - 1 / rate); again wrong !!!

        tt += ((it + rate - 1) / rate);
        return tt;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        //int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());;
        int k = high;

        while (low <= high) {
            int midRate = low + (high - low) / 2;

            // if(netTimeTaken(piles, midRate) == h)
            // return midRate;
            int time = netTimeTaken(piles, midRate);

            if (time <= h) 
            {
                //k = min(k, midRate);
                k = midRate;
                high = midRate - 1;
            }
        
            else{
                low = midRate + 1;
            }
        }

        return k;
    }
};
