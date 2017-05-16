class Solution {
public:
    void createMap(map<char,int> &M)
    {
        M['I'] = 1;
        M['V'] = 5;
        M['X'] = 10;
        M['L'] = 50;
        M['C'] = 100;
        M['D'] = 500;
        M['M'] = 1000;
    }
    int romanToInt(string s) {
        map<char,int>M;
        createMap(M);
        int prev;
        int num = 0;
        for(int i=0; i<s.size(); i++)
        {
            int th = M[s[i]];
            if(i != 0)
            {
                if(th > prev)
                {
                    num -=  2*prev;
                }
                
            }
            num +=th;
            prev = th;
        }
        return num;
    }
};