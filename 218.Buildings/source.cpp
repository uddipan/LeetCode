class Solution {
public:
    struct endPoint
    {
        int pos, height;
        bool isLeft;
        endPoint(int p, int h, bool b)
        {
            height = h;
            pos = p;
            isLeft = b;
        }
    };
    
    static bool mySort(endPoint a, endPoint b)
    {
        if(a. pos < b.pos)return true;
        if((a.pos == b.pos) && (a.height < b.height))return true;
        return false;
    }
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> RET;
        if(buildings.empty())return RET;
        vector<endPoint>VP;
        for(auto i=0; i<buildings.size(); i++)
        {
            endPoint L(buildings[i][0], buildings[i][2], true),
            R(buildings[i][1], buildings[i][2], false);
            VP.push_back(L);
            VP.push_back(R);
        }
        sort(VP.begin(), VP.end(), mySort);
        
        int currHeight = 0;
        multiset<int> S;
        S.insert(0);
        for(auto i=0; i<VP.size(); i++)
        {
            if(VP[i].isLeft)
            {
                S.insert(VP[i].height);
                currHeight = *(S.rbegin());
                if(currHeight == VP[i].height)
                {
                    RET.push_back({VP[i].pos,VP[i].height});
                }
            }
            else
            {
                auto it = S.find(VP[i].height);
                S.erase(it);
                currHeight = *(S.rbegin());
                if(currHeight < VP[i].height)
                {
                    RET.push_back({VP[i].pos, currHeight});
                }
                
            }
        }
        
        
        auto idx2 = 0;
        while(idx2 < RET.size() - 1)
        {
            if(RET[idx2].first == RET[idx2+1].first)
            {
                RET.erase(RET.begin() + idx2);
            }
            else{
                idx2++;
            }
        }
        
        
        auto idx = 1;
        while(idx < RET.size())
        {
            if(RET[idx].second == RET[idx-1].second)
            {
                RET.erase(RET.begin() + idx);
            }
            else
            {
                idx++;
            }
        }
        return RET;
    }
};