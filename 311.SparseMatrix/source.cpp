class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> Res;
        if(A.empty() || B.empty())return Res;
        vector<map<int,int>>Amap, Bmap;
        vector<int>tmp(B[0].size(),0);
        Res = vector<vector<int>>(A.size(),tmp);
        for(unsigned u=0; u<A.size(); u++)
        {
            map<int,int>tmp;
            for(unsigned v=0; v<A[0].size(); v++)
            {
                if(A[u][v] != 0)
                {
                    tmp[v] = A[u][v];
                }
            }
            Amap.push_back(tmp);
        }
        
        for(unsigned v=0; v<B[0].size(); v++)
        {
            map<int,int> tmp;
            for(unsigned u=0; u<B.size(); u++)
            {
                if(B[u][v] != 0)
                {
                    tmp[u]  = B[u][v];
                }
            }
            Bmap.push_back(tmp);
        }
        
        for(int r=0; r<A.size(); r++)
        {
            for(int c=0; c<B[0].size(); c++)
            {
                int sum = 0;
                //A[r]*B[c]
                for(auto it = Amap[r].begin(); it != Amap[r].end(); ++it)
                {
                    auto it2 = Bmap[c].find(it->first);
                    if(it2 != Bmap[c].end())
                    {
                        sum += (it2->second)*(it->second);
                    }
                }
                Res[r][c] = sum;
            }
            
        }
        return Res;
    }
};