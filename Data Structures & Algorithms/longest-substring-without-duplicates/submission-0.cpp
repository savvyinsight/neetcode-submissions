class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char,int> CharIndex;
        int l = 0;
        for(int r = 0;r<s.size();r++){
            if(CharIndex.find(s[r]) != CharIndex.end() && CharIndex[s[r]] >= l){
                l = CharIndex[s[r]] + 1;
            }
            maxLen = max(maxLen,r-l+1);
            CharIndex[s[r]] = r;
        }
        return maxLen;
    }
};
