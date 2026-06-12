class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
        for(char c:s){
            if(c>='a' && c<='z') ns+=c;
            else if(c>='0' && c<='9') ns+=c;
            else if(c>='A' && c<='Z') ns+=(c-'A'+'a');
        }

        int l = 0,r = ns.size()-1;
        while(l<r){
            if(ns[l] != ns[r]) return false;
            ++l;
            --r;
        }
        return true;
    }
};
