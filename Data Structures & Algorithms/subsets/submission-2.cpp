class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};

        for(auto num:nums){
            int n = ans.size();
            for(int i = 0;i<n;++i){
                vector<int> subset = ans[i];
                subset.push_back(num);
                ans.push_back(subset);
            }
        }

        return ans;
    }
};
