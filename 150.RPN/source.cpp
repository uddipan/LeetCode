class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>S;
        int a,b;
        string c,d;
        for(auto i=0; i<tokens.size(); i++)
        {
            if(tokens[i].compare("+") == 0)
            {
                a = S.top();S.pop();
                b = S.top();S.pop();
                S.push(a + b);
            }
            else if(tokens[i].compare("-") == 0)
            {
                a = S.top();S.pop();
                b = S.top();S.pop();
                S.push(b - a);
            }
            else if(tokens[i].compare("*") == 0)
            {
                a = S.top();S.pop();
                b = S.top();S.pop();
                S.push(a * b);
            }
            else if(tokens[i].compare("/") == 0)
            {
                a = S.top();S.pop();
                b = S.top();S.pop();
                S.push(b / a);
            }
            else
            {
                S.push(atoi(tokens[i].c_str()));
            }
        }
        return S.top();
    }
};