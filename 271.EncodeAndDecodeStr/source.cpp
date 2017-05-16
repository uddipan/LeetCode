class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string S;
        for(auto i = 0; i<strs.size(); i++)
        {
            S += strs[i];
            S.push_back('\0');
        }
        return S;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string>V;
        if(s.empty())return V;
        //s. pop_back();
        //if(s.empty())return V;
        size_t idx = s.find('\0');
        while(idx != string::npos)
        {
            V.push_back(s.substr(0,idx));
            s = s.substr(idx+1);
            idx = s.find('\0');
        }
        if(!s.empty())V.push_back(s);
        return V;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// assuming '\0' is not part of any string