class KthLargest {
        priority_queue<int, vector<int>, greater<int>> minHeap;
       int value;
public:
    KthLargest(int k, vector<int>& nums) {
        value = k;
        for(auto i:nums) minHeap.push(i);
    }
    
    int add(int val) {
        minHeap.push(val);
        
        while(minHeap.size() > value){
            minHeap.pop();
        }
        return minHeap.top();
    }
};
