class Solution {
public:
    int compareVersion(string version1, string version2) {
        size_t pos1,pos2;
        vector<int>v1,v2;
        
        do
        {
            pos1 = version1.find('.');
            string tmp = version1.substr(0,pos1);
            v1.push_back(atoi(tmp.c_str()));
            version1 = version1.substr(pos1+1);
        }while(pos1 != string::npos);
        
        do
        {
            pos2 = version2.find('.');
            string tmp = version2.substr(0,pos1);
            v2.push_back(atoi(tmp.c_str()));
            version2 = version2.substr(pos2+1);
        }while(pos2 != string::npos);
        
        while(v1.size() < v2.size())v1.push_back(0);
        while(v2.size() < v1.size())v2.push_back(0);
        
        for(int i=0; i<v1.size(); i++)
        {
            if(v1[i] < v2[i])return -1;
            else if(v1[i] > v2[i])return 1;
        }
        return 0;
    }
};