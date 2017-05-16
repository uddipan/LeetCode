// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0)return -1;
        int idx1 = 0, idx2 = 1;
        while(idx2 < n )
        {
            if(knows(idx1,idx2))
            {
                idx1 = idx2;
            }
            idx2++;
        }
        
        for(int i=0; i<n; i++)
        {
            if(i == idx1)continue;
            if(knows(idx1,i) || !knows(i,idx1))return -1;
        }
        return idx1;
    }
};