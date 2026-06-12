class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1;
        while(true){
            long long time = 0;
            for(int p : piles){
                time += (p+s-1)/s;
            }

            if(time<=h){
                return s;
            }
            s++;
        }
    }
};
// 1 2 3 4
// k =1 , this needs most hours, minimum k
// k = 4, this needs less hours, maximum k
// so we need to find the k, when hours less than and close to
// h.
// pile/speed + 1 - 1/speed
// 