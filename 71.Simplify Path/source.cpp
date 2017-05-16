class Solution {
public:
    string simplifyPath(string path) {
        if(path.empty())return path;
        stack<string>S;
        size_t sz = path.find('/');
        while(sz != string::npos)
        {
            string tmp = path.substr(0,sz);
            if(tmp == ".." && !S.empty())
            {
                S.pop();
            }
            else if(tmp != "" && tmp != "." &&  tmp != "..")
            {
                S.push(tmp);
            }
            path = path.substr(sz+1);
            sz = path.find('/');
        }
        if(path == ".." && !S.empty())
        {
            S.pop();
        }
        
        else if(path != "" && path != "." && path != "..")
        {
            S.push(path);
        }
        string res;
        while(!S.empty())
        {
            res = "/" + S.top() + res ;
            S.pop();
        }
        return res.empty()?"/":res;
    }
};