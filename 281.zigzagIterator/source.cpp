class ZigzagIterator {
public:
    bool b;
    int sz1, sz2;
    int iter1, iter2;
    vector<int> v1,v2;
    ZigzagIterator(vector<int>& V1, vector<int>& V2) {
        v1 = V1;
        v2 = V2;
        b = !v1.empty();
        sz1 = v1.size();
        sz2 = v2.size();
        iter1 = 0;
        iter2 = 0;
    }
    
    int next() {
        if(b)
        {
            if(iter2 < sz2)b = false;
            if(iter1 < sz1)return v1[iter1++];
        }
        else
        {
            if(iter1 < sz1)b = true;
            if(iter2 < sz2)return v2[iter2++];
        }
    }
    
    bool hasNext() {
        return (iter1 < sz1 || iter2 < sz2);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */