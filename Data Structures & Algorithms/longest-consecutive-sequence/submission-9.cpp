class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> set(nums.begin(),nums.end());

        int longestLen = 0;
        for(int num:nums){
            if(!set.count(num-1)){
                int streak = 1;
                while(set.count(num+streak)){
                    streak++;
                }
                longestLen = max(longestLen,streak);
            }
        }
        return longestLen;
    }
};
