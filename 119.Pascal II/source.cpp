class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> V(rowIndex+1,0);
        int tmp, tmp2;
        V[0] = 1;
        if(rowIndex == 0)return V;
        V[1] = 1;
        if(rowIndex == 1)return V;
        for(auto i=2; i<=rowIndex; i++)
        {
            tmp = V[0];
            for(auto j=1; j<=i; j++)
            {
                tmp2 = V[j];
                V[j] = tmp + tmp2;
                tmp = tmp2;
            }
        }
        
    }
};