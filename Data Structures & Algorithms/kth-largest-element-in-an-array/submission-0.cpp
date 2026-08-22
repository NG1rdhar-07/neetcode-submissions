class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i : nums)
        pq.push(i);

        int x = k-1;
        //int prev = INT_MIN;

        while(x > 0 && !pq.empty()){
            // int tE = pq.top();

            // while(prev == tE)
            // {
            //     pq.pop();
            // }

            // prev = tE;
            pq.pop();
            x--;
        }

        return pq.top();
    }
};
