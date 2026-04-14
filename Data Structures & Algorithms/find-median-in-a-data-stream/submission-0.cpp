class MedianFinder {
    priority_queue<int> pq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
    }

    
    double findMedian() {
        int n = pq.size();
        vector<int> x;
        for(int i = 0 ; i < n ; i++){
            x.push_back(pq.top());pq.pop();
        }
        cout << n << endl;
        double ans =  (n%2 != 0) ? (double)x[n/2] : (double)(x[n/2] + x[(n-1)/2])/2;
        
        for(int i = 0 ; i < n ; i++){
           pq.push(x[i]);
        }
        return ans;
    }
};
