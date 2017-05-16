class MedianFinder {
public:
    priority_queue<int> minHeap;
    priority_queue<int, vector<int>, greater<int> >maxHeap;
    // Adds a number into the data structure.
    void addNum(int num) {
        if(minHeap.empty())
        {
            minHeap.push(num);
            return;
        }
        else if(maxHeap.empty())
        {
            if(num < minHeap.top())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                return;
            }
            else
            {
                maxHeap.push(num);
                return;
            }
        }
        if(num <= minHeap.top())
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }
        if(maxHeap.size() > minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size() + 1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
        {
            return double(minHeap.top() + maxHeap.top())/2.0;
        }
        else
        {
            return minHeap.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();