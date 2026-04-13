class Solution {
public:
    int lastStoneWeight(vector<int>& stone) {
        priority_queue<int> maxHeap;
        int n = stone.size();
        for(int i = 0 ; i < n ; i++) maxHeap.push(stone[i]);

        while(maxHeap.size()>1){
            
            int value1 = maxHeap.top();
            maxHeap.pop();
            int value2 = maxHeap.top();
            maxHeap.pop();

            cout << value1 << " " << value2 << endl;

            if(value1 != value2) {
                maxHeap.push(abs(value1-value2));
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();

    }
};
