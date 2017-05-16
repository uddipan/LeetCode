class Solution {
public:
    string justify(vector<string>&interim, int maxWidth, bool last)
    {
        if(interim.size() == 1)
        {
            int cnt = maxWidth - interim[0].size();
            string res = interim[0];
            res.append(string(cnt,' '));
            return res;
        }
        int sz = 0;
        for(int i=0; i<interim.size(); i++)
        {
            sz += interim[i].size();
        }
        int blanks = maxWidth - sz;
        int cnt = interim.size()-1;
        string res = interim[0];
        if(last)
        {
            for(int i=1; i<interim.size(); i++)
            {
                res += " ";
                res+= interim[i];
                blanks--;
            }
            res += string(blanks, ' ');
            return res;
        }
        
        int x = blanks/cnt, y = blanks%cnt;
        for(int i=1; i<interim.size();i++)
        {
            int z = y?1:0;
            res += string(x+z, ' ');
            res += interim[i];
            if(y>0)y--;
        }
        return res;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        if(words.empty())return res;
        if(maxWidth == 0)return vector<string>(1,"");
        
        int idx = 0;
        int cnt = 0;
        vector<string> interim;
        while(idx < words.size())
        {
            cnt += words[idx].size();
            if(cnt > maxWidth)
            {
                res.push_back(justify(interim,maxWidth,false));
                interim.clear();cnt = 0;
            }
            else
            {
                cnt ++;
                interim.push_back(words[idx]);
                idx++;
            }
        }
        res.push_back(justify(interim,maxWidth,true));
        return res;
    }
};