class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            while(!stk.empty() && heights[stk.top()]>heights[i]){
                int right = i;
                int index = stk.top();stk.pop();
                int left = stk.empty()?-1:stk.top();

                res = max(res,(right-left-1)*heights[index]);
            }
            stk.push(i);
        }

        while(!stk.empty()){
            int right = n;
            int index = stk.top();stk.pop();
            int left = stk.empty()?-1:stk.top();
            res = max(res,(right-left-1)*heights[index]);
        }
        return res;
    }
};
