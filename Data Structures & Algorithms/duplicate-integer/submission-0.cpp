class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> record;
        for(int num:nums){
            if(record[num]) return true;
            else record[num] = true;
        }
        return false;
    }
};