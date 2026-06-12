class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int n = heights.size();
        for(int i = 0;i<n;i++){
            //left part
            int l = i-1;
            while(l>=0 && heights[l]>=heights[i]){
                l--;
            }

            // right part
            int r = i+1;
            while(r<n && heights[r]>=heights[i]){
                r++;
            }

            res = max(res, (r-l-1)*heights[i]);
        }
        return res;
    }
};
