class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m) return false;
        unordered_map<char,int> cntS;
        unordered_map<char,int> cntT;
        for(int i = 0;i<n;++i){
            ++cntS[s[i]];
            ++cntT[t[i]];
        }
        return cntS==cntT;
    }
};
