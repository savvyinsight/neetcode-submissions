class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pairs;// p,s
        for(int i = 0;i<speed.size();i++){
            pairs.push_back({position[i],speed[i]});
        }

        sort(pairs.begin(),pairs.end());

        vector<double> times;
        for(int i = pairs.size()-1;i>=0;i--){
            double t = (target-pairs[i].first)/(double)pairs[i].second;
            times.push_back(t);
        }
        int cnt = 1;
        double prev = times[0];
        for(int i = 1;i<times.size();i++){
            if(prev>=times[i]){
                // same fleet
            }else{
                cnt++;
                prev = times[i];
            }
        }
        return cnt;
    }
};
