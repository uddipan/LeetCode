class Solution {
public:
    int xmin = INT_MAX, xmax = INT_MIN, ymin = INT_MAX, ymax = INT_MIN;
    vector<vector<bool>>visited;
    void visit(int x, int y, vector<vector<char>>& image)
    {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size())return;
        if(image[x][y] == '0')return;
        if(visited[x][y])return;
        xmin = min(xmin, x);
        xmax = max(xmax, x);
        ymin = min(ymin, y);
        ymax = max(ymax, y);
        visited[x][y] = true;
        
        visit(x-1,y,image);
        visit(x+1,y,image);
        visit(x,y-1,image);
        visit(x,y+1,image);
    }
    
    int minArea(vector<vector<char>>& image, int x, int y) {
        vector<bool>tmp(image[0].size(), false);
        visited = vector<vector<bool>>(image.size(), tmp);
        visit(x,y,image);
        return (xmax-xmin + 1)*(ymax-ymin+1);
        
    }
};