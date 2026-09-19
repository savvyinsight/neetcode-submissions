class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string token = tokens.back();
        tokens.pop_back();

        if(token != "+" && token != "-" && token != "*" && token != "/") return stoi(token);

        int right = evalRPN(tokens);
        int left = evalRPN(tokens);

        if(token == "+") return left+right;
        else if(token == "-") return left-right;
        else if(token == "*") return left*right;
        else return left/right;
    }
};
