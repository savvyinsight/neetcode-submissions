/*
Thinking process:
1.stack: we need to find which day will be warmer in the future
, so we want to look at future day and compare with past day
,if future day warmer than past day, we can update past day
index in result. 
TC:O(n),SC:O(n)

2.Brute Force: 
    - use i and j , for every element, we need to find the 
    warmer day, if yes, we can calculate index and break.
    - O(n**2),O(n)
*/
class Solution {
public:
    // stack
    vector<int> dailyTemperatures_s(vector<int>& tem) {
        int n = tem.size();
        vector<int> res(n,0);
        stack<pair<int,int>> stk; // temp,index

        for(int i = 0;i<n;i++){
            while(!stk.empty() && tem[i]>stk.top().first){
                int idx = stk.top().second;
                stk.pop();
                res[idx] = i-idx;
            }
            stk.push({tem[i],i});
        }
        return res;
    }

    // brute force
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n = tem.size();
        vector<int> res(n,0);

        for(int i = 0;i<n-1;i++){
            for(int j = i+1;j<n;j++){
                if(tem[j]>tem[i]){
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};
