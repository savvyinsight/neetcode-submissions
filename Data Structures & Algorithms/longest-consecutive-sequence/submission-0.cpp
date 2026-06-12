class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(),nums.end());

        int maxLen = 0;
        for(int num:numSet){
            //check current num is the starting element
            if(numSet.find(num-1) != numSet.end()) continue;
            int curLen = 1;
            int nextNum = num+1;
            while(numSet.find(nextNum) != numSet.end()){
                ++curLen;
                ++nextNum;
            }
            maxLen = max(maxLen,curLen);
        }
        return maxLen;
    }
};
