class Solution {
public:
    vector<int>M;
    int num(int n)
    {
        if(M[n] != 0)return M[n];
        
        for(int i=0; i<n; i++)
        {
            M[n] += num(i)*num(n-i-1);
        }
        return M[n];
    }
    int numTrees(int n) {
        M = vector<int>(n+1,0);
        M[0] = 1;
        M[1] = 1;
        return num(n);
    }
};