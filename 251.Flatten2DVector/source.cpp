class Vector2D {
public:
    int row,col,x,y;
    vector<vector<int>> matrix;
    Vector2D(vector<vector<int>>& vec2d) {
        
        for(int i=0; i<vec2d.size(); i++)
        {
            if(!vec2d[i].empty())
            {
                matrix.push_back(vec2d[i]);
            }
        }
        if(matrix.empty())
        {
            row = 0;col = 0;
            x = 0; y = 0;
            return;
        }
        row = matrix.size();
        col = matrix[matrix.size()-1].size();
        x = 0;
        y = 0;
    }
    
    int next() {
        if(!hasNext())return -1;
        int s = matrix[x][y];
        y++;
        if(matrix[x].size() == y)
        {
            x++;
            y=0;
        }
        return s;
    }
    
    bool hasNext() {
        return ((x < row -1)  || ((x == row-1) && y < col));
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */