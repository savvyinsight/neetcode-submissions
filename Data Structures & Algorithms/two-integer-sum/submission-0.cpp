class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i = 0;i<nums.size();++i){
            if(record.find(nums[i]) != record.end()){
                return {record[nums[i]],i};
            }
            record[target-nums[i]] = i;
        }
        return {};
    }
};
