class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(const auto& num:nums){
            mp[num]++;
        }

        vector<pair<int,int>> freq;
        for(auto& p:mp){
            freq.push_back({p.second,p.first});
        }
        sort(freq.begin(),freq.end(),[](const pair<int,int>& a,const pair<int,int>& b){
            return a.first > b.first;
        });

        vector<int> res;
        for(int i = 0;i<k;i++){
            res.push_back(freq[i].second);
        }
        
        return res;
    }
};
