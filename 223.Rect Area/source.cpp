class Solution {
public:
    int common(pair<int,int>A, pair<int,int>B, pair<int,int> C, pair<int, int>D, bool isVert)
    {
        int P,Q;
        if(isVert)
        {
            P = min(A.second, C.second);
            Q = max(B.second, D.second);
            if(Q > P)return 0;
            return (P - Q);
        }
        else
        {
            P = max(A.first, C.first);
            Q = min(B.first, D.first);
            if(P > Q)return 0;
            return (Q - P);
        }
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        pair<int,int> a1(A,B), b1(C,B), c1(E,F), d1(G,F);
        pair<int,int> a2(A,D), b2(A,B), c2(E,H), d2(E,F);
        int comm = common(a1,b1,c1,d1,false)*common(a2,b2,c2,d2,true);
        return (C-A)*(D-B) + (G-E)*(H-F) - comm;
    }
};