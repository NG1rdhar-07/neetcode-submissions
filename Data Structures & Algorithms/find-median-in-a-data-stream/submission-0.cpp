class MedianFinder {
public:

    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxH.empty() || maxH.top() >= num)
        maxH.push(num);
        else
        minH.push(num);

        if(maxH.size() > minH.size()+1)
        {
            minH.push(maxH.top());
            maxH.pop();
        }

        else if(maxH.size() < minH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        int size = minH.size() + maxH.size();
        
        if(size % 2 == 0)
        return (double)(minH.top() + maxH.top()) / 2;
        else
        return maxH.top();
    }
};
