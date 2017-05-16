class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>>V;
        if(strings.empty())return V;
        map<string,vector<string>>M;
        
        for(int i=0; i<strings.size(); i++)
        {
            string tmp = strings[i];
            int shift = tmp[0] - 'a';
            for(int j=0; j<tmp.size(); j++)
            {
                int x = (tmp[j] - shift + 26)%26;
                tmp[j] = 'a' + x;
            }
            if(M.find(tmp) != M.end())
            {
                M[tmp].push_back(strings[i]);
            }
            else
            {
                M[tmp] = vector<string>(1,strings[i]);
            }
        }
        for(auto it = M.begin(); it != M.end(); ++it)
        {
            V.push_back(it->second);
        }
        return V;
    }
};