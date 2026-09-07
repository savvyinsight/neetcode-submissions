class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(const int& num:nums){
            mp[num]++;
        }
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> min_heap;
        for(auto& p:mp ){
            min_heap.push({p.second,p.first});
            if(min_heap.size()>k){
                min_heap.pop();
            }
        }

        vector<int> res;
        for(int i = 0;i<k;i++){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
