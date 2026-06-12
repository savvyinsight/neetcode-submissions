class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        vector<int> res(n,0);
        stack<pair<int,int>> stk; // temp,index

        for(int i = 0;i<n;i++){
            while(!stk.empty() && tem[i]>stk.top().first){
                int idx = stk.top().second;
                stk.pop();
                res[idx] = i-idx;
            }
            stk.push({tem[i],i});
        }
        return res;
    }
};
