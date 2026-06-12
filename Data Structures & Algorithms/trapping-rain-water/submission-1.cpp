class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int res = 0,l = 0,r = height.size()-1;
        int lMx = height[l],rMx = height[r];
        while(l<r){
            if(lMx < rMx){
                l++;
                lMx = max(lMx,height[l]);
                res += lMx-height[l];
            }else{
                r--;
                rMx = max(rMx,height[r]);
                res += rMx-height[r];
            }
        }
        return res;
    }
};
