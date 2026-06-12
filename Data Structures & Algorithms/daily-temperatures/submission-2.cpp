class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        vector<int> res(n,0);
        for(int i = n-2;i>=0;i--){
            int j = i+1;
            while(j<n && tem[j] <= tem[i]){
                if(res[j] == 0){
                    j = n;
                    break;
                }
                j += res[j];
            }

            if(j<n){
                res[i] = j-i;
            }
        }
        return res;
    }
};
