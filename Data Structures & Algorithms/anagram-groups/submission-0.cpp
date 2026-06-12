class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> res;
        for(const string& s:strs){
            string sS = s;
            sort(sS.begin(),sS.end());
            res[sS].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto & pair:res){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
