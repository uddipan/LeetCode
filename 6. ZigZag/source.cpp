class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>VS(numRows,"");
        if(numRows == 1)return s;
        int step = 1, rowId = 0;
        for(int i=0; i<s.size(); i++)
        {
            VS[rowId].push_back(s[i]);
            if(rowId == 0)step = 1;
            if(rowId == numRows-1)step = -1;
            rowId += step;
        }
        string ret;
        for(int i=0; i<numRows;i++)
        {
            ret += VS[i];
        }
        return ret;
    }
};