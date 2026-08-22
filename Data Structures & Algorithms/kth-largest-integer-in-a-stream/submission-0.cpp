class KthLargest {
public:

    priority_queue<int> pq;
    int kVal = 0;

    KthLargest(int k, vector<int>& nums) {  
        kVal = k;

        for(int i : nums)
        pq.push(i);   
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp = pq;
        int x = kVal-1;
        while(x > 0)
        {
            temp.pop();
            x--;
        }

        return temp.top();
    }
};
