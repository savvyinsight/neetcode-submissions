class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(const int& i:nums){
            ++count[i];
        }

        vector<pair<int,int>> arr(count.begin(),count.end());
        sort(arr.begin(),arr.end(),[](auto& a,auto& b){
            return a.second>b.second;
        });
        
        vector<int> ans(k);
        for(int i = 0;i<k;++i){
            ans[i] = arr[i].first;
        }
        return ans;
    }
};
