class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(const int& i: nums){
            ++count[i];
        }

        vector<vector<int>> freq(nums.size()+1);
        for(const auto& entry:count){
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for(int i = freq.size()-1;i>0;--i){
            for(int x:freq[i]){
                res.push_back(x);
                if(k == res.size()){
                    return res;
                }
            }
        }
        return res;
    }
};
