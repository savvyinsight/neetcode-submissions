class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0;i<strs[0].size();++i){
            for(const string& s:strs){
                if(i == s.size() || s[i] != strs[0][i]){
                    return s.substr(0,i);
                }
            }
        }
        return strs[0];
    }
};