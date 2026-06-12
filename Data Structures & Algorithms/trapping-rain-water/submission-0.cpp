class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size(), res = 0;
        
        for(int i=0;i<n;i++){
            int lMax = height[i],rMax = height[i];

            for(int j = 0;j<i;j++){
                lMax = max(lMax,height[j]);
            }

            for(int j = i+1;j<n;j++){
                rMax = max(rMax,height[j]);
            }

            res += min(lMax,rMax)-height[i];
        }
        return res;
    }
};
