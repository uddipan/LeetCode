class Solution {
public:
    int chan(int n)
    {
        int x = 0;
        while(n)
        {
            x += (n%10)*(n%10);
            n/=10;
        }
        return x;
    }
    bool isHappy(int n) {
        int cnt = 0;
        while(n != 1 && cnt < 100)
        {
            n = chan(n);
            cnt ++;
        }
        if(cnt < 100)return true;
        return false;
    }
};