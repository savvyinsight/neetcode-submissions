class Solution {
public:
    bool check(string& str){
        unordered_set<char> set;
        for(int i = 0;i<str.size();i++){
            if (set.find(str[i]) != set.end()){
                return false;
            }
            set.insert(str[i]);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLen = 0,n = s.size();
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                string str = s.substr(i,j-i+1);
                if(check(str)){
                    maxLen = max(maxLen,j-i+1);
                }
            }

        }
        return maxLen;
    }
};
