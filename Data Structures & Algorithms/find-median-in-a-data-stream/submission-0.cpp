class MedianFinder {
public:

    priority_queue<int> maxSmallHeap;
    priority_queue<int,vector<int>,greater<int>> minLargeHeap;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxSmallHeap.push(num);
        if(!minLargeHeap.empty() && maxSmallHeap.top()>minLargeHeap.top()){
            minLargeHeap.push(maxSmallHeap.top());
            maxSmallHeap.pop();
        }

        if(maxSmallHeap.size()>minLargeHeap.size()+1){
            minLargeHeap.push(maxSmallHeap.top());
            maxSmallHeap.pop();
        }

        if(minLargeHeap.size()>maxSmallHeap.size()+1){
            maxSmallHeap.push(minLargeHeap.top());
            minLargeHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxSmallHeap.size()==minLargeHeap.size()){
            return ((maxSmallHeap.top()+minLargeHeap.top())/2.0);
        }
        else if(maxSmallHeap.size()>minLargeHeap.size()){
            return maxSmallHeap.top();
        }
        else{
            return minLargeHeap.top();
        }
    }
};
