// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cnt = 0;
        int tmp = 0;
        char *dst = buf;
        
        while(n >= 4)
        {
            tmp = read4(buf);
            buf += tmp;
            cnt += tmp;
            if(tmp < 4)return cnt;
            n -= 4;
        }
        if(n)
        {
            tmp = read4(buf);
            tmp = min(n,tmp);
            buf += tmp;
            cnt += tmp;
        }
        
        return cnt;
    }
};