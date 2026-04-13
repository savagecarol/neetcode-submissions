

struct Compare {
    bool operator()(const pair<vector<int>, int>& a, 
                    const pair<vector<int>, int>& b) const {
        return a.second < b.second; // max heap
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue< pair<vector<int>, int>, vector<pair<vector<int>, int>>, Compare> pq;
        int n = points.size();
        vector<vector<int>> ans;

        for(int i = 0 ; i < n ; i++){
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            pq.push({points[i] , distance});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;

    }
};
