class Solution {
public:

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        //     if(a[0] == b[0]) return a[1] < b[1];
        //     return a[0] < b[0];
        // });

        int i = 0 , n = intervals.size();
        
        vector<vector<int>> ans;

        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n){
              ans.push_back(intervals[i]);
              i++; 
        }
        return ans;

    }
};
