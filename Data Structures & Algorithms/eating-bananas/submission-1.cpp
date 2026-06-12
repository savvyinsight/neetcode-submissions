class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int kmin = 1,kmax = 0;
        for(int p:piles){
            kmax = max(kmax,p);
        }

        int l = kmin,r = kmax;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long total_time = 0;
            for(int p:piles){
                total_time += (p+mid-1)/mid;
            }

            if(total_time<=h){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return l;
    }
};
