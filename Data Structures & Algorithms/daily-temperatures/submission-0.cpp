class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans;
        
        for(int i = n-1 ; i >=0 ; i--){
            if(st.empty()){
                ans.push_back(0);
            }
            if(!st.empty())
            {
                while(!st.empty()){
                    if(temperatures[st.top()] > temperatures[i]) {
                        ans.push_back((st.top()-i));
                        break;
                    }
                    st.pop();
                }
                if(st.empty()) ans.push_back(0);
            }
            st.push(i);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
