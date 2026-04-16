class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    });

        int n = intervals.size();
        stack<vector<int>> st;
        vector<vector<int>> ans;
        st.push(intervals[0]);

        for(int i = 1 ; i < n ; i++){
                vector<int> prev = st.top();
                if(prev[1] >= intervals[i][0]){
                    st.pop();
                    st.push({min(prev[0] , intervals[i][0]) , max(prev[1] , intervals[i][1])});
                }
                else st.push(intervals[i]);
        }

        while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
