class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> stk;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && 
                tokens[i] != "/" && tokens[i] != "*"){
                    stk.push(stoi(tokens[i]));
            }else{
                int right = stk.top();
                stk.pop();
                int left = stk.top();
                stk.pop();
                string v_string = tokens[i];
                char c = v_string[0];
                switch(c){
                    case '+':
                        res = left + right;
                        break;
                    case '-':
                        res = left - right;
                        break;
                    case '*':
                        res = left * right;
                        break;
                    case '/':
                        res = left / right;
                        break;
                }
                stk.push(res);
            }
        }
        return stk.top();
    }
};
