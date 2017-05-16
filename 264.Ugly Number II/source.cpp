class Solution {
public:
    int nthUglyNumber(int n) {
        long toRet = 1;
        set<long>A,B,C;
        A.insert(2);
        B.insert(3);
        C.insert(5);
        
        for(int i=2; i<=n; i++)
        {
            auto itA = A.begin(), itB = B.begin(), itC = C.begin();
            toRet = min(min(*itA,*itB), *itC);
            
            if(toRet == *itA)
            {
                A.erase(A.begin());
                A.insert(toRet*2);
                B.insert(toRet*3);
                C.insert(toRet*5);
            }
            else if(toRet == *itB)
            {
                B.erase(B.begin());
                B.insert(toRet*3);
                C.insert(toRet*5);
            }
            else if(toRet == *itC)
            {
                C.erase(C.begin());
                C.insert(toRet*5);
            }
        }
        return toRet;
    }
};