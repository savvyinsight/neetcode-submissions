class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> rec;
        for(int i = 0;i<nums.size();++i){
            rec.push_back({nums[i],i});
        }
        sort(rec.begin(),rec.end());

        int l = 0,r = nums.size()-1;
        while(l<r){
            int tmp = rec[l].first + rec[r].first;
            if( tmp == target){
                return {min(rec[l].second,rec[r].second),max(rec[l].second,rec[r].second)};
            }else if(tmp < target){
                ++l;
            }else{
                --r;
            }
        }
        return {};
    }
};
