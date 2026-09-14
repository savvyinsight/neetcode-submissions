class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());

        int ans = 0;
        for(int num:nums){
            if(s.find(num-1) != s.end()) continue;
            int streak = 1, curr = num;
            while(s.find(++curr) != s.end()){
                streak++;
            }
            ans = max(ans,streak);
        }
        return ans;
    }
};
