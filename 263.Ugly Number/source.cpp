class Solution {
public:
    int factorize(int num, int k)
    {
        while(num%k == 0)
        {
            num /=k;
        }
        return num;
    }
    bool isUgly(int num) {
        if(num == 0)return false;
        num = factorize(num,2);
        num = factorize(num,3);
        num = factorize(num,5);
        
        return (num == 1);
    }
};