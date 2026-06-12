class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i = 1;i<strs.size();++i){
            int j = 0;
            while(j<min(strs[i].size(),prefix.size())){
                if(strs[i][j] != prefix[j]) break;
                ++j;
            }
            prefix = prefix.substr(0,j);
        }
        return prefix;
        }
};