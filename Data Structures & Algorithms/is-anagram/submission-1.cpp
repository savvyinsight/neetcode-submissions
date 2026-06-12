class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n!=m) return false;
        unordered_map<int,int> cntS;
        unordered_map<int,int> cntT;
        for(char x:s){
            ++cntS[x];
        }
        for(char x:t){
            ++cntT[x];
        }
        for(char x:s){
            if(cntS[x]!=cntT[x]) return false;
        }
        return true;
    }
};
