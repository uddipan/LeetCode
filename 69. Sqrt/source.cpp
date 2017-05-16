class Solution {
public:
    int mySqrt(int x) {
        long L = 0, R = x;
        
        while(L <= R)
        {
            long mid = (L+R)/2;
            long s = mid*mid;
            if(s <= long(x))
            {
                L = mid+1;
            }
            else
            {
                R = mid-1;
            }
        }
        return int(L-1);
    }
};