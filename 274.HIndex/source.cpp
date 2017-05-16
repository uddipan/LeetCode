class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty())return 0;
        int sz = citations.size();
        vector<int>tmp(sz+1, 0);
        for(int i=0; i<citations.size(); i++)
        {
            if(citations[i] >= sz)
            {
                tmp[sz]++;
            }
            else
            {
                tmp[citations[i]]++;
            }
        }
        for(int i=sz-1; i>=0; i--)
        {
            tmp[i] += tmp[i+1];
        }
        int cnt = 0;
        for(int i=0; i<=sz; i++)
        {
            if(i > tmp[i])break;
            cnt = max(cnt, i);
        }
        return cnt;
    }
};