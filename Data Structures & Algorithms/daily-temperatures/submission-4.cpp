class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        vector<int> res(n);

        stack<pair<int,int>> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && st.top().first<tem[i]){
                int idx = st.top().second;
                res[idx] = i-idx;
                st.pop();
            }
            st.push({tem[i],i});
        }
        return res;
    }
};
