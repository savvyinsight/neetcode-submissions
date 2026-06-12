class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = "";
        for(string& s:strs){
            res+=to_string(s.size())+',';
        }
        res+='#';
        for(string& s:strs){
            res+=s;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s.empty()) return {};
        
        vector<int> sizes;
        int i = 0;
        while(s[i]!='#'){
            string cur = "";
            while(s[i] != ','){
                cur+=s[i++];
            }
            sizes.push_back(stoi(cur));
            ++i;
        }

        vector<string> res;
        ++i;
        for(int sz:sizes){
            res.push_back(s.substr(i,sz));
            i += sz;
        }
        return res;
    }
};
